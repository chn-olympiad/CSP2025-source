#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+6;
int t,n,dp[maxn][4],ans;
struct Node{
    int x,y,z;
}a[maxn];
struct NODEE{
    int a,num;
}d[maxn*2];
bool cmp(Node a,Node b){
    return a.x>b.x;
}
bool gdy(NODEE a,NODEE b){
    return a.a>b.a;
}
void san(int s,int c,int a1,int a2,int a3){
    if(a1>n/2||a2>n/2||a3>n/2)return;
    if(c==n+1){
        ans=max(ans,s);
        return;
    }
    san(s+a[c].x,c+1,a1+1,a2,a3);
    san(s+a[c].y,c+1,a1,a2+1,a3);
    san(s+a[c].z,c+1,a1,a2,a3+1);
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        bool f=true,ff=true;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y)f=false;
            if(a[i].z)ff=false;
        }
        if(n<=30)san(0,1,0,0,0);
        else if(ff&&f){
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)ans+=a[i].x;
        }
        else if(ff){
            int tot[2]={0,0};
            for(int i=1;i<=n;i++){
                d[2*i-1].a=a[i].x;
                d[2*i].a=a[i].y;
                d[2*i-1].num=1;
                d[2*i].num=2;
            }
            sort(d+1,d+2*n+1,gdy);
            for(int i=1;i<=2*n;i++){
                if(tot[0]==n/2&&d[i].num==1)continue;
                if(tot[1]==n/2&&d[i].num==2)continue;
                ans+=d[i].a;
                tot[d[i].num-1]++;
            }
        }
        else{
            for(int i=1;i<=n;i++)ans+=max(a[i].x,max(a[i].y,a[i].z));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
