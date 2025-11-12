#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],ans,s1,s2;
void dfs(int good,int k,int c0,int c1,int c2){
    if(c0+c0>n||c1+c1>n||c2+c2>n)return ;
    if(k==n-1){
        ans=max(ans,good);
        return ;
    }
    dfs(good+a[k+1],k+1,c0+1,c1,c2);
    dfs(good+b[k+1],k+1,c0,c1+1,c2);
    dfs(good+c[k+1],k+1,c0,c1,c2+1);
    return ;
}
void dfs2(int good,int k,int c0,int c1){
    if(k==n-1){
        ans=max(ans,good);
        return ;
    }
    if(c0+c0<n)dfs2(good+a[k+1],k+1,c0+1,c1);
    if(c1+c1<n)dfs2(good+b[k+1],k+1,c0,c1+1);
    return ;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        s1=0,s2=0,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i],s1+=b[i],s2+=c[i];
        if(s1==0&&s2==0){
            sort(a,a+n);
            for(int i=0;i+i<n;i++)ans+=a[n-i+1];
            cout<<ans<<'\n';
        }else if(s2==0)dfs2(a[0],0,1,0),dfs2(b[0],0,0,1),cout<<ans<<'\n';
        else dfs(a[0],0,1,0,0),dfs(b[0],0,0,1,0),dfs(c[0],0,0,0,1),cout<<ans<<'\n';
    }
    return 0;
}
