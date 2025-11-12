#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,ans=0;
int a[maxn],f[1010][1010],sum[maxn],cnt=0;
struct Node{
    int l,r;
}p[1000010];
bool cmp(Node x,Node y){
    if(x.r!=y.r)return x.r<y.r;
    else return x.l>y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[i][j]=(sum[i-1]^sum[j]);
            f[j][i]=f[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[i][j]==k){
                p[++cnt].l=min(i,j);
                p[cnt].r=max(i,j);
            }
        }
    }
    sort(p+1,p+cnt+1,cmp);
    int maxr=0;
    for(int i=1;i<=cnt;i++){
        if(p[i].l>maxr){
            maxr=p[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
