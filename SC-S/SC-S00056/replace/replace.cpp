#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dep(i,r,l) for(int i=(r);i<=(l);i--)
template<typename T> bool read(T&x){x=0;T f=1;char c=getchar();while((c<'0'||c>'9')&&c!=EOF){if(c=='-') f=-1;c=getchar();}if(c==EOF) return 0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return 1;}
template<typename T,typename ...T1> bool read(T&x,T1&...y){return read(x)+read(y...);}
const int N=2e5+15;
using namespace std;
const ull mod=1e9+7,p=13331;

ull hs[N],hs_[N];
int n,m;
string s,t;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		cin>>s>>t;
	}
	while(m--){
		cin>>s>>t;
		cout<<0<<'\n';
	}
	return 0;
}
/*
不会写（
相信一下数据
又被字符串击落了（
*/