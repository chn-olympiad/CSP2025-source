#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define x first
#define y second
#define all(a) (a).begin(),(a).end()
#define FRE(f) {freopen(f".in","r",stdin);freopen(f".out","w",stdout);}
#define LL long long
#ifdef DB
#define Z(x...) cerr<<"\t#"<<__LINE__<<" : ",db(#x,x),cerr<<"\n";
void db(const char*s){}
template<typename T,typename...TT>void db(const char*s,T x,TT...y){
	while((*s)&&(*s)!=',')cerr<<*s++;
	s++;
	cerr<<" = "<<x<<"  ";
	db(s,y...);
}
#define ZZ(a,l,r) cerr<<"\t@"<<__LINE__<<" : "<<#a<<" = ";fr(IT,l,r)cerr<<a[IT]<<" ";cerr<<"\n";
#else
#define Z(x...)
#define ZZ(x...) 
#endif
#define int LL
const int N=1e6+33,N1=20,mod=998244353;
int n,m;
int a[N],b[N];
int f[1<<N1][N1];
#define popc __builtin_popcount
signed main(){
    FRE("employ");
    cin>>n>>m;
    fr(i,1,n){
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    fr(i,1,n){
        cin>>b[i];
    }
    

    f[0][0]=1;
    fr(z,0,(1<<n)-1){
        int sz=popc(z);
        fr(j,0,n)if(f[z][j]){
            fr(p,1,n)if(!(z>>p-1&1)){
                (f[z|(1<<p-1)][j+(a[sz+1]==0 || (j>=b[p]))]+=f[z][j])%=mod;
            }
        }
    }
    int ans=0;
    fr(i,m,n){
        ans=(ans+f[(1<<n)-1][n-i])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
