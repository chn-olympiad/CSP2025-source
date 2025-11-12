#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int pre[1005];
int dp[1005][1005];
struct Node{
    int l,r;
}b[1000005];
bool cmp(Node x,Node y){
    if(x.r-x.l!=y.r-y.l)return (x.r-x.l)<=(y.r-y.l);
    return x.l<y.l;
}
bool vis[1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    pre[1]=a[1];
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[i][j]=pre[j]^pre[i-1];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dp[i][j]==k){
                b[++cnt].l=i;
                b[cnt].r=j;
            }
        }
    }
    sort(b+1,b+cnt+1,cmp);
    int ans=0;
    for(int j=1;j<=cnt;j++){
        int tmp1=b[j].l;
        int tmp2=b[j].r;
        bool flg=false;
        for(int i=tmp1;i<=tmp2;i++){
            if(vis[i]){
                flg=true;
                break;
            }
        }
        if(!flg){
            ans++;
            for(int i=tmp1;i<=tmp2;i++){
                vis[i]=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
