#include <bits/stdc++.h>
using namespace std;
using tp=long long;
#define For(i,l,r) for(tp i(l),i##sc03(r);i<=i##sc03;++i)
#define FoR(i,r,l) for(tp i(r),i##sc03(l);i>=i##sc03;--i)
#define ALL(G) G.begin(),G.end()
#define SIZ(G) tp(G.size())
#define pb emplace_back
#define pf emplace_front
#define ep emplace
#define gp make_pair
#define fr first
#define sd second
// inline tp read(){
//     tp x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
//     while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();return x*f;
// }inline bool write(tp x,char ch='\n'){return printf("%lld",x),putchar(ch),true;}
template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a<b?a:b;}
template<class T,class Q>inline bool Cmax(T&a,Q b){return a<b?a=b,true:false;}
template<class T,class Q>inline bool Cmin(T&a,Q b){return a>b?a=b,true:false;}
constexpr tp N=200200;
tp n,q;unordered_map<tp,tp>buc[1000100];
string s[N][3],t[N][3];
map<string,string>mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    For(i,1,n){
        cin>>s[i][1]>>s[i][2];
    }
    if(n<=100){
        For(i,1,n)mp[s[i][1]]=s[i][2];
        For(K,1,q){
            cin>>t[K][1]>>t[K][2];
            tp len=SIZ(t[K][1]),ans=0;
            For(l,0,len-1)For(r,l,len-1){
                string cur="";
                For(i,l,r)cur.push_back(t[K][1][i]);
                auto it=mp.find(cur);
                if(it!=mp.end()){
                    string C=mp[cur];
                    string now="";
                    For(i,0,l-1)now.push_back(t[K][1][i]);
                    now+=C;
                    For(i,r+1,len-1)now.push_back(t[K][1][i]);
                    if(now==t[K][2])++ans;
                }
            }cout<<ans<<'\n';
        }return 0;
    }
    For(i,1,n){
        tp A=s[i][1].find('b'),B=s[i][2].find('b');
        if(i<=10)cerr<<A<<' '<<B<<'\n';
        ++buc[SIZ(s[i][1])][B-A];
    }
    For(K,1,q){
        cin>>t[K][1]>>t[K][2];tp ans=0;
        if(SIZ(t[K][1])!=SIZ(t[K][2])){cout<<0<<'\n';continue;}
        tp A=t[K][1].find('b'),B=t[K][2].find('b');
        tp la=A+1;For(i,1,la)ans+=buc[i][B-A];cout<<ans<<'\n';
    }
    return 0;
}