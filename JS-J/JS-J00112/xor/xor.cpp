#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0,s,x;
int a[1010][1010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&s);
        if(s==k)
        {
            cnt++;
            x=0;
        }
        else
        {
            a[1][++x]=s;
            for(int i=2;i<=x;i++)
            {
                a[i][x]=(a[i-1][x-1]^a[i-1][x]);
                if(a[i][x]==k)
                {
                    cnt++;
                    x=0;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}

