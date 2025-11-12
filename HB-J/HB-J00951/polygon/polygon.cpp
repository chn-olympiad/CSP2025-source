#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
int n,a[5010];
int max(int a,int b){
    if(a<b) return b;
    return a;
}
int ax[10010],bx[10010];
void dle1(int x){
    if(x==1) return ;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            x/=i;
            ax[i]++;
            i--;
        }
    }
    if(x!=1) ax[x]++;
}
void dle2(int x){
    if(x==1) return ;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            x/=i;
            bx[i]++;
            i--;
        }
    }
    if(x!=1) bx[x]++;
}
int C(int x,int y){
    int ans=1;
    memset(bx,0,sizeof(bx));
    memset(ax,0,sizeof(ax));
    if(y*2>x) y=x-y;
    if(y==0) return 1;
    for(int i=x-y+1;i<=x;i++) dle1(i);
    for(int i=1;i<=y;i++) dle2(i);
    for(int i=1;i<=5000;i++){
        int z=ax[i]-bx[i];
        for(int j=1;j<=z;j++){
            ans*=i;
            ans%=Mod;
        }
    }
    return ans;
}
int sol1(){
    int ans=0;
    for(int i=3;i<=n;i++){
        ans+=C(n,i);
        ans%=Mod;
    }
    return ans;
}
bool cho[110];
bool check(){
    int sum=0,maxn=0;
    bool f=0;
    for(int i=1;i<=n;i++){
        if(cho[i]==1){
            f=1;
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
    }
    if(f==0) return 0;
    if(sum>2*maxn) return 1;
    return 0;
}
int sol2(int k){
    int ans=0;
    if(k==n+1){
        if(check()) ans++;
        return ans;
    }
    cho[k]=1;
    ans+=sol2(k+1);
    cho[k]=0;
    ans+=sol2(k+1);
    return ans%Mod;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(a,0,sizeof(a));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(a[n]==1){
        printf("%lld",sol1());
        return 0;
    }
    memset(cho,0,sizeof(cho));
    printf("%lld ",sol2(1));
    return 0;
}
