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
#ifdef DBZ
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
const int N=5e6+33;
int n,q;
#define sz(a) ((int)a.size())
#define nn(a) ((int)(a.size())-1)
string a[(int)3e5][2],b[(int)3e5][2];
vector<int>ca[N],cb[N];
typedef vector<int> vint;
vint f[N],g[N];
int ans[N];
bool match(vint a,vint b){
    fr(i,0,nn(a)-nn(b)){
        if(equal(all(b),a.begin()+i))return 1;
    }
    return 0;
}
vint calc(string a,string b){
    vint ret;
    assert(nn(a)==nn(b));
    fr(i,0,nn(a)){
        int v=(a[i]==b[i]?a[i]:a[i]+1+b[i]*26);
        ret.eb(v);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    FRE("replace");
    cin>>n>>q;
    fr(i,1,n){
        fr(j,0,1)cin>>a[i][j];
        int c=0;
        fr(k,0,nn(a[i][0])){
            c+=(a[i][0][k]!=a[i][1][k]);
        }
        Z(i,c);
        ca[c].eb(i);
    }
    fr(i,1,q){
        fr(j,0,1)cin>>b[i][j];
        int c=0;
        fr(k,0,nn(b[i][0])){
            c+=(b[i][0][k]!=b[i][1][k]);
        }
        Z(i,c);
        cb[c].eb(i);
    }
    fr(c,0,N-1)if(cb[c].size()){
        Z(c);
        int fi=0,gi=0;
        for(int i:ca[c]){
            f[++fi]=calc(a[i][0],a[i][1]);
            Z(i);
            ZZ(f[fi],0,nn(f[fi]));
        }
        for(int i:cb[c]){
            auto cur=calc(b[i][0],b[i][1]);
            fr(it,1,fi){
                if(match(cur,f[it]))ans[i]++;
            }
        }
    }
    fr(i,1,q){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
