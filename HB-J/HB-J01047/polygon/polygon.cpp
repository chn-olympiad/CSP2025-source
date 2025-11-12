#include<bits/stdc++.h>
using namespace std;
int n,a[10010],b[21],cur,c[21],ans;
const int Mod=998244353;
bool cmp(int x,int y){return x>y;}
int C(int x,int y){
    if(y>x/2) return C(x,x-y);
    long long mul=1;
    for(int i=1;i<=y;i++){mul=mul*(x-i+1)/i%Mod;}
    return int(mul);
}
bool check1(){
    for(int i=1;i<=n;i++) if(a[i]!=1) return false;
    return true;
}
int s1(){
    int cnt=0;
    for(int i=3;i<=n;i++){cnt+=C(n,i);cnt%=Mod;}
    return cnt;
}
void s2(int l){
    while(l>0){
        b[++cur]=l%2;
        l/=2;
    }
}
void check(){
    int uuu=0,cur1=0,summ=0;
    for(int i=1;i<=n;i++) if(b[i]==1) uuu++;
    if(uuu<3) return ;
    for(int i=1;i<=n;i++) if(b[i]==1) c[++cur1]=a[i];
    int ppp=c[1];
    for(int i=2;i<=cur1;i++) summ+=c[i];
    if(summ>ppp) ans++;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(n==3){
        if(a[1]>=a[2]+a[3]) cout<<0;
        else cout<<1;
    }
    else if(check1()) cout<<s1();
    else{
        int k=pow(2,n);
        for(int i=1;i<=k;i++){
            cur=0;
            s2(i);
            check();
        }
        cout<<ans;
    }
    return 0;
}

