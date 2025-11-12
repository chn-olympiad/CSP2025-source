#include <bits/stdc++.h>
using namespace std;

struct per
{
    int sco;
    bool f;
};

bool cmp(per a, per b)
{
    if(a.sco > b.sco)
        return true;
    return false;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("./seat.in");
    fout.open("./seat.out");
    int n, m;
    fin >> n >> m;
    vector<per> arr(n*m+1);
    for(int i = 0; i < n*m; i++)
    {
        fin >> arr[i].sco;
        arr[i].f = false;
    }
    arr[0].f = true;

    sort(arr.begin(), arr.end(), cmp);
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(j % 2 == 1)
            {
                if(arr[(j-1)*n+i-1].f)
                {
                    fout << j << " " << i;
                    return 0;
                }
            }
            else
            {
                if(arr[j*n-i].f)
                {
                    fout << j << " " << n-i+2;
                    return 0;
                }
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
