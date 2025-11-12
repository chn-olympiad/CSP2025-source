#include<bits/stdc++.h>
using namespace std;
int m,n,a,b,q;
int r,k[1000],ans[15][15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>m>>n>>r;
    for (int i = 0; i < m*n-1; i++)
    {
        cin>>k[i];
    }
    k[m*n-1] = r;    
    int l = 1;
    while(l != 0)
    {
        l = 0;
        for (int i = 0; i < m*n-1; i++)
        {
            if(k[i] < k[i+1])
            {
            l = 1;
            int o = k[i];
            k[i] = k[i+1];
            k[i+1] = o;
            }
        }
    }
    for (int i = 0; i < m*n; i++)
    {
        if(k[i] == r)
        {
            a = i;
            break;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        b++;
        if(b%2 == 0)
        {
            for(int j = n; j > 0; j--)
            {
                if(q == a)
                {
                    cout<<i<<' '<<j;
                }
                q++;
            }
        }
        else
        {
            for(int j = 1; j <= n; j++)
            {
                if(q == a)
                {
                    cout<<i<<' '<<j;
                }
                q++;
            }
        }
        
    }
}