#include<bits/stdc++.h>
using namespace std;
int l,s[5001],z,most,ans=0,v[5001];
void dfs(int i,int j)
{

    if(j==i+1&&most*2<l) ans++;
    else{

        for(int a=0;a<z;a++)
        {
            if(v[a]==0)
            {
                v[a]=1;
                most=max(most,s[a]);
                l+=s[a];
                dfs(i,j+1);
                v[a]=0;
                l-=s[a];
            }

        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon."out","w",stdout);
    cin>>z;
    for(int i=0;i<z;i++)
    {
        cin>>s[i];
    }
    for(int e=3;e<z;e++)
    {
        l=0;
        most=0;
        dfs(e, 1);
    }
    cout<<ans%998244353;
}
