#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())

#define pb push_back
#define fi first
#define se second


using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;

const int N=505,mod=998244353;
int f[1<<18][19];
int n,m,s[N],c[N];
int count(int x){
    int res=0;
    while(x>0)res+=1,x-=x&(-x);
    return res;
}
void add(int &x,int v){x=(1ll*x+v)%mod;}
void sub1(){
    f[0][0]=1;
    rep(i,0,(1<<n)-1){
        int ct=count(i);
        rep(j,0,ct)
            rep(k,0,n-1)if(!(i>>k&1))add(f[i|(1<<k)][j+((ct-j<c[k+1])&&s[ct+1])],f[i][j]);
    }
    int ans=0;
    rep(j,m,n)add(ans,f[(1<<n)-1][j]);
    cout<<ans<<'\n';
}
bool check_al(){return n==m;}
void sub2(){
    rep(i,1,n)if(s[i]==0||c[i]==0){
        cout<<0<<'\n';
        return;
    }
    cout<<1<<'\n';
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);



    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    rep(i,1,n){
        char ch;cin>>ch;
        s[i]=ch-'0';
    }
    rep(i,1,n)cin>>c[i];
    if(n<=18)sub1();
    else if(check_al())sub2();




    return 0;
}
