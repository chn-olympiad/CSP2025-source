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
const int N=1e5+33;
int n;
int a[N][3],v[N][3];
void so(){
    cin>>n;
    int ans=0;
    fr(i,1,n){
        fr(j,0,2){
            cin>>v[i][j];
            a[i][j]=j;
        }
        sort(a[i]+0,a[i]+2+1,[i](int x,int y){
            return v[i][x]>v[i][y];
        });
        Z(i);
        ZZ(a[i],0,2);

        ans+=v[i][a[i][0]];
    }
    Z(ans);
    int cnt[3]={};
    fr(i,1,n)cnt[a[i][0]]++;
    int mj=-1;
    fr(w,0,2){
        if(cnt[w]>n/2){
            mj=w;
            break;
        }
    }
    if(mj!=-1){
        static int val[N],vi;
        vi=0;
        fr(i,1,n){
            if(a[i][0]==mj){
                int nx=a[i][1];
                val[++vi]=v[i][mj]-v[i][nx];
            }
        }
        ZZ(val,1,vi);
        sort(val+1,val+vi+1);
        // assert(vi==cnt[mj]&&vi>n/2);
        int C=cnt[mj];
        fr(i,1,vi-(n/2)){
            ans-=val[i];    
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    FRE("club");
    int T;
    cin>>T;
    while(T--)so();
    return 0;
}
