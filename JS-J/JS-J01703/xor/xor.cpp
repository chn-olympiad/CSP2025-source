#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



typedef struct qj
{
    int s;
    int e;
    int l;
}QJ;


bool compare(QJ u, QJ v)
{
    if (u.l > v.l) return false;
    if (u.l < v.l) return true;
    if (u.s > v.s) return false;
}


int dfs_search(vector<QJ> &b, vector<bool> &c, int d=0)
{
    //cout << "debug: " << d << " ";
    //for (int i=0; i<int(c.size()); i++)
    //{
        //cout << c[i];
    //}
    //cout << endl;
    int max_n = d;
    int tmp_ind = 0;
    for (int i=0; i<int(b.size()); i++)
    {
        bool t = true;
        for (int j=b[tmp_ind].s; j<=b[tmp_ind].e; j++)
        {
            if (c[j])
            {
                t = false;
                tmp_ind++;
                break;
            }
        }
        if (t)
        {
            //cout << "debug27: " << b[0].s << " ";
            for (int j=b[tmp_ind].s; j<=b[tmp_ind].e; j++)
            {
                //cout << j << " ";
                c[j] = 1;
            }
            //cout << endl;
            QJ tmp_qj;
            tmp_qj.s = b[tmp_ind].s;
            tmp_qj.e = b[tmp_ind].e;
            tmp_qj.l = b[tmp_ind].l;
            b.erase(b.begin() + tmp_ind);
            int tmp_n = dfs_search(b, c, d + 1);
            if (tmp_n > max_n)
            {
                max_n = tmp_n;
            }
            //cout << "debug: " << max_n << " " << d << endl;
            for (int j=tmp_qj.s; j<=tmp_qj.e; j++)
            {
                c[j] = 0;
            }
            b.push_back(tmp_qj);
        }
    }
    return max_n;
}


int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    unsigned int n, k;
    cin >> n >> k;
    vector<unsigned int> a(n);
    vector<QJ> b;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for (int i=0; i<n; i++)
    {
        unsigned int tmp_int = 0;
        for (int j=i; j<n; j++)
        {
            tmp_int ^= a[j];
            if (tmp_int == k)
            {
                //cout << tmp_int << " " << i << " " << j << endl;
                QJ tmp_qj;
                tmp_qj.s = i;
                tmp_qj.e = j;
                tmp_qj.l = j - i + 1;
                b.push_back(tmp_qj);
            }
        }
    }
    sort(b.begin(), b.end(), compare);
    vector<bool> c(n, 0);
    if (n < 1000)
    {
        cout << dfs_search(b, c);
    }
    else
    {
        int sum = 0;
        int tmp_ind = 0;
        for (int i=0; i<int(b.size()); i++)
        {
            bool t = true;
            for (int j=b[tmp_ind].s; j<=b[tmp_ind].e; j++)
            {
                if (c[j])
                {
                    t = false;
                    tmp_ind++;
                    break;
                }
            }
            if (t)
                {
                //cout << "debug27: " << b[0].s << " ";
                for (int j=b[tmp_ind].s; j<=b[tmp_ind].e; j++)
                {
                    //cout << j << " ";
                    c[j] = 1;
                }
                //cout << endl;
                QJ tmp_qj;
                tmp_qj.s = b[tmp_ind].s;
                tmp_qj.e = b[tmp_ind].e;
                tmp_qj.l = b[tmp_ind].l;
                b.erase(b.begin() + tmp_ind);
                sum ++;
            }
        }
        cout << sum;
    }
    return 0;
}
