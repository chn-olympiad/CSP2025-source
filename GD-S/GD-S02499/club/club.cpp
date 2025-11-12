#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
    int num,id;
}a[maxn],b[maxn],c[maxn];
bool cmp(node x,node y){
    return x.num>y.num;
}
int vis[maxn],n;
int solve(int i,int j,int z,int cnt,int ans){
	
    int vis1=i-1,vis2=j-1,vis3=z-1;
    while(ans<n){
    		while(vis[a[i].id]==1) i++;
			
    		while(vis[b[j].id]==1) j++;
    		while(vis[c[z].id]==1) z++;
            if(a[i].num>=b[j].num&&a[i].num>=c[z].num){
                if(vis[a[i].id]==0&&vis1<n/2){
                    cnt+=a[i].num;
                    vis[a[i].id]=1;i++;vis1++;
                }
            } 
            else if(c[z].num>=b[j].num&&c[z].num>=a[i].num){
                if(vis[c[z].id]==0&&vis3<n/2){
                    cnt+=c[z].num;
                    vis[c[z].id]=1;z++;vis3++;
                }
            } 
            else if(b[j].num>=a[i].num&&b[j].num>=c[z].num){
                if(vis[b[j].id]==0&&vis2<n/2){
                    cnt+=b[j].num;
                    vis[b[j].id]=1;j++;vis2++;
                }
            } 
            
            ans++;
        }
        return cnt;
}
int solve2(){
    int ans=0,res=0;
    for(int i=1;i<=n/2;i++) ans+=a[i].num,vis[a[i].id]=1;
    for(int i=1;i<=n;i++) if(vis[b[i].id]!=1)ans+=b[i].num,vis[b[i].id]=1;
    memset(vis,0,sizeof vis);
    ans=0;
    res=ans;
    for(int i=1;i<=n/2;i++) ans+=b[i].num,vis[b[i].id]=1;
    for(int i=1;i<=n;i++) if(vis[a[i].id]!=1)ans+=a[i].num,vis[a[i].id]=1;
    res=max(ans,res);
    ans=0;
    for(int i=1;i<=n/2;i++) ans+=c[i].num,vis[c[i].id]=1;
    for(int i=1;i<=n;i++) if(vis[a[i].id]!=1)ans+=a[i].num,vis[a[i].id]=1;
    res=max(ans,res);
    return res;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].num>>b[i].num>>c[i].num;
            a[i].id=b[i].id=c[i].id=i;
        }
        sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);sort(c+1,c+n+1,cmp);
        int ans=0;
        int i=1,j=1,z=1,res=0,cnt=0;
        cnt+=a[1].num;i++;ans++;vis[a[1].id]=1;
        res=max(res,solve(i,j,z,cnt,ans));
        memset(vis,0,sizeof vis);
        i=1,j=1,z=1,cnt=0;
        cnt+=b[1].num;j++;vis[b[1].id]=1;
        res=max(res,solve(i,j,z,cnt,ans));
        memset(vis,0,sizeof vis);
        i=1,j=1,z=1,cnt=0;
        cnt+=c[1].num;z++;vis[c[1].id]=1;
        res=max(res,solve(i,j,z,cnt,ans));
        res=max(res,solve2());
		cout<<res<<"\n";
    }
    return 0;
}