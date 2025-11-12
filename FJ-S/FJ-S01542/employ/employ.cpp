#include <bits/stdc++.h>
#define popcnt __builtin_popcount
typedef long long ll;
using namespace std;
const int N=505,P=998244353,S=18;

int n,m,c[N],p[1<<S|5];
char a[N];
int f[S][1<<S|5];
void sol0(){
    int ans=0;
    for(int i=0;i<(1<<n);++i) p[i]=i;
    sort(p,p+(1<<n),[&](int x,int y){return popcnt(x)<popcnt(y);});
    f[0][0]=1;
    for(int t=1;t<(1<<n);++t){
        int s=p[t],x=popcnt(s);
        //cerr<<"*s: "<<s<<"  x: "<<x<<endl;
        for(int i=0;i<=x;++i){
            for(int j=0;j<n;++j) if((s>>j)&1){
                //cerr<<"*"<<i<<" "<<x<<" "<<c[j]<<endl;
                if(i<x && a[x]=='1' && c[j+1]>i){
                    f[i][s] = (f[i][s]+ f[i][s^(1<<j)])%P; // not run
                    //cerr<<"not run "<<s<<" <-- "<<(s^(1<<j))<<endl;
                }else if(i>0 && (a[x]=='0' || c[j+1]<i)){
                    f[i][s] = (f[i][s]+ f[i-1][s^(1<<j)])%P; // run
                    //cerr<<"run "<<s<<" <-- "<<(s^(1<<j))<<endl;
                }
                //cerr<<"f["<<i<<"]["<<s<<"]: "<<f[i][s]<<endl;
            }
        }
    }
    for(int i=0;i<=n-m;++i){
        ans=(ans+f[i][(1<<n)-1])%P;
    }
    printf("%d\n",ans);
}

void soln(){

}

void solA(){
    sort(c+1,c+1+n);
    int ans=1;
    for(int i=1;i<=n;++i) ans=1ll*ans*i%P;
    printf("%d\n",ans);

}

int main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    for(int i=1;i<=n;++i) scanf("%d",c+i);
    bool flag=1;
    for(int i=1;i<=n;++i) if(a[i]!='1') flag=0;

    sol0();
    return 0;
}