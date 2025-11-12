#include<bits/stdc++.h>
using namespace std;
int l[5005];
int n;
int v[5005];
int choose(int b,long long s,int v[])
{

    long long ans=0;
    if(b>2)
    {
        ans++;
        for(int i=1;i<=b;i++)
        {
            if(l[v[i]]*2>=s)
            {
                ans--;
                break;
            }
        }
    }
    if(b<n)
    {
        for(int i=v[b]+1;i<=n;i++)
        {
            bool flag=false;
            int j=1;
            for(;j<=b;j++)
            {
                if(v[j]==i)
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                v[b+1]=i;
                ans+=choose(b+1,s+l[i],v);
            }
        }
    }
    return ans%998244353;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
    }
    long long ans=choose(0,0,v);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
