#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            ans++;
            vis[i]=1;
        }    
    } cout<<ans<<endl;   
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
        {
            int m=a[i];
            int j=i;
            while(vis[j+1]==0)
            {
                j++;
                m^=a[j];
                if(m==k)
                {
                    ans++;
                    for(int t=0;t<=j;t++)
                        vis[i+t]=1;
                }
            }
        }    
    cout<<ans;
    return 0;
}