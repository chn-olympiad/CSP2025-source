#include <bits/stdc++.h>
using namespace std;

struct p {
    int s, e;
    p(int s, int e) {
        this->e = e;
        this->s = s;
    }
};


bool cmp(p a, p b) {
    if(a.e < b.e) {
        return true;
    }
    if(a.s == b.s && a.e < b.e) {
        return true;
    }
    return false;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("./xor.in");
    fout.open("./xor.out");
    int n, k;
    fin >> n >> k;
    vector<int> arr(n);
    vector<p> qu;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
            {
                if(arr[i] == k)
                    qu.push_back(p(i,j));

            }
            else
            {
                int t = arr[i];
                for(int m = i+1; m <= j; m++)
                {
                    t ^= arr[m];
                }
                if(t == k)
                {
                    qu.push_back(p(i, j));
                }
            }
        }

    }
    sort(qu.begin(), qu.end(), cmp);
    vector<p> tmp;
    tmp.push_back(qu[0]);
    for(int i = 1; i < qu.size(); i++) {
        if(qu[i].s > qu[i].e)
            tmp.push_back(qu[i]);
    }

    fout << tmp.size();
    fin.close();
    fout.close();
    return 0;
}
