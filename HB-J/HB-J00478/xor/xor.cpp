#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long n,k,ans=0;
/*int dfs(int l,int r)
{
    if(l==n || l==r)    return 0;
    for(int i=l;i<=r;i++)
    {
        if(a[i]!=-1){
            int x=l,y=a[i];
            for(int j=i+1;j<=r;j++)
            {
                if(a[j]==-1){
                    x=j-1;
                    break;
                }
                y^=a[j];
                if(y==k){
                    int w=dfs(i,x);
                    ans+=max(1,w);
                }
            }
        }

    }
    return ans;
}*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k){
            ans++;
            a[i]=-1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1){
            int r=i,l;
            int x=a[i];
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]==-1){
                    break;
                }
                x^=a[j];
                if(x==k){
                    ans++;
                    l=j;
                    break;
                }
            }
            for(int j=r;j<=l;j++)
                a[j]=-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*for(int i=l;i<=r;i++)
    {
        if(a[i]!=-1){
            int r=i,l;
            int x=a[i];
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]==-1){
                    break;
                }
                x^=a[j];
                if(x==k){
                    ans++;
                    l=j;
                    break;
                }
            }
            for(int j=r;j<=l;j++)
                a[j]=-1;
        }
    }*/
