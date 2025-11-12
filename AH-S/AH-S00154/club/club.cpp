#include<bits/stdc++.h>
using namespace std;
int t,n,cnt,ans;
int a[100005][4],f[100005][5],d[100005];
int b[100005],e[100005];
struct AC{
    int x,id,zb;
}c[100005];
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
    if(x==n+1){
        ans=max(ans,sum);
        return ;
    }
    if(cnt1<(n/2)) dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
    if(cnt2<(n/2)) dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
    if(cnt3<(n/2)) dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);

}
bool cmp(int x,int y){
    return x>y;
}
bool cmp1(AC t,AC w){
    return t.x>w.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        cnt=0;
        bool f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
                c[++cnt].x=a[i][j];
                c[cnt].zb=j;
                c[cnt].id=i;
            }
            d[i]=a[i][1];
            if(a[i][3]!=0 || a[i][2]!=0) f=1;
        }
        if(f==0){
            sort(d+1,d+n+1,cmp);
            for(int i=1;i<=(n/2);i++){
                ans+=d[i];
            }
        }else if(n<=15){
            dfs(1,0,0,0,0);
        }else{
            sort(c+1,c+cnt+1,cmp1);
            for(int i=1;i<=cnt;i++){
                if(b[c[i].id]==0 && e[c[i].zb]<(n/2)){
                    ans+=c[i].x;
                    b[c[i].id]++;
                    e[c[i].zb]++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
