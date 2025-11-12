#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,k,a[maxn],ans;
bool vis[maxn];
int sw(int x,int y)
{
    int sum=1;
    if(y==0)return sum;
    for(int i=1;i<=y;i++)
        sum*=x;
    return sum;
}
int xx(int x,int y)
{
    int sum=0;
    bool a1[30]={},b[30]={},c[30]={};
    for(int i=20;i>=0;i--){
        if(x>=sw(2,i))
        {
            x-=sw(2,i);
            a1[i]=1;
        }
        if(x==0)break;
    }
    for(int i=20;i>=0;i--){
        if(y>=sw(2,i))
        {
            y-=sw(2,i);
            b[i]=1;
        }
        if(y==0)break;
    }
    for(int i=20;i>=0;i--)
    {
        if(a1[i]==b[i])c[i]=0;
        else c[i]=1;
    }
    for(int i=20;i>=0;i--)
        if(c[i]==1)sum+=sw(2,i);
    return sum;
}
bool check(int l,int r)
{
    int sum=a[l];
    for(int i=l+1;i<=r;i++){
        if(vis[i]==1)return 0;
        sum=xx(sum,a[i]);
    }
    if(sum==k)
    {
        for(int i=l;i<=r;i++)
            vis[i]=1;
        return 1;
    }
    else return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k){
            vis[i]=1;
            ans++;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(check(i,j))ans++;
    cout<<ans;
	return 0;
}
