#include<bits/stdc++.h>
using namespace std;
int n,maxn;
struct xxxx
{
    int a,b,c;
} a[5005];
void dfs1(int xuan,int le,int ri,int to,int val)
{
    if(le==n/2) {
        int ti=0;
        for(int i=xuan;i<=n;i++)
        {
            ti+=a[i].b;
        }
        maxn=max(maxn,val+ti);
        return ;
    }
    if(ri==n/2){
        int ti=0;
        for(int i=xuan;i<=n;i++)
        {
            ti+=a[i].a;
        }
        maxn=max(maxn,val+ti);
        return ;
    }
    dfs1(xuan+1,le+1,ri,to,val+a[xuan].a);
    dfs1(xuan+1,le,ri+1,to,val+a[xuan].b);
    return ;
}
void dfs2(int xuan,int l,int m,int r,int to,int val){
    if(to==xuan-1&&l<=n/2&&m<=n/2&&r<=n/2){
        maxn=max(maxn,val);
  //  cout<<maxn<<endl;
        return ;
    }
    if(l<n/2) dfs2(xuan+1,l+1,m,r,to,val+a[xuan].a) ;
    if(m<n/2) dfs2(xuan+1,l,m+1,r,to,val+a[xuan].b);
    if(r<n/2) dfs2(xuan+1,l,m,r+1,to,val+a[xuan].c);
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
            bool A,B;
    A=B=false;
    cin>>n;
        for(int i=1;i<=n;i++){
             cin>>a[i].a>>a[i].b>>a[i].c;
             if(a[i].b!=0||a[i].c!=0) A=true;
        }
        if(!A){
            int dp[1001];
            for(int i=1;i<=n;i++) dp[i]=a[i].a;
            sort(dp+1,dp+n+1,greater<int>());
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=dp[i];
            }
            cout<<dp<<endl;
        }
        else {
            dfs2(0,0,0,0,n,0);
            cout<<maxn<<endl;
        }
        maxn=0;
    }
    return 0;
}
