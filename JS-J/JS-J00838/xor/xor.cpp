#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10,P=1e3+10;
int n,k,cnt,ans,a[N],f[P*P],p[P*P],q[P*P],s[P][P];
bool pd;
struct node{
    int l,r;
}seq[P*P];
bool cmp(node a,node b){
    return a.r<b.r;
}
void solve1(){
    for(int i=1;i<=n;i++){
        if(a[i]==1&&a[i+1]==1){
            ans++;
            i++;
        }
        else if(a[i]==0) ans++;
    }
    printf("%d",ans);
}
void solve2(){
    for(int i=1;i<=n;i++){
        if(a[i]==1) ans++;
    }
    printf("%d",ans);
}
void solve3(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s[i][j]=s[i][j-1]^a[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[i][j]==k) seq[++cnt]={i,j};
        }
    }
    sort(seq+1,seq+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        p[i]=seq[i].l;
        q[i]=seq[i].r;
    }
    for(int i=1;i<=cnt;i++){
        f[i]=1;
        for(int j=1;j<cnt;j++){
            if(seq[j].r<seq[i].l) f[i]=max(f[i],f[j]+1);
        }
        ans=max(ans,f[i]);
    }
    printf("%d",ans);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>1) pd=true;
    }
    if(!pd){
        if(k==0) solve1();
        else solve2();
        return 0;
    }
    else if(n<=1010){
        solve3();
        return 0;
    }
    return 0;
}
