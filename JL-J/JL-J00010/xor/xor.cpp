#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans,box[5];
bool vis[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
        if(a[i]==0)box[0]++;
        vis[i]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(!vis[j])break;
            int x=s[i];
            x^=s[j-1];
            if(x==k)
            {
                ans++;
                vis[i]=false;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
