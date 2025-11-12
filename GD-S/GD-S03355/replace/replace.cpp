#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define lson (now<<1)
#define rson (now<<1|1) 
#define fi first
#define se second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
typedef std::pair<int,int> pii;
typedef std::pair<string,string> pss;
constexpr int MAXN = (int)5e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = (int)1e9+7;
inline void IO(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}
int n,q,f,ans;
int l1,r1,l2,r2;
char tmp[MAXN],t1[MAXN],t2[MAXN],s1[MAXN],s2[MAXN];
struct node{
	int l1,l2,r1,r2;
};
std::vector<node>b; 
//ÐÔÖÊB
//25 pts 
signed main(){
	IO();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	FOR(i,0,n){
		cin>>s1>>s2;
		int flag = 1;
		l1 = l2 = r1 = r2 = 0;
		for(int j=0;s1[j];++j){
			if(flag&&s1[j]=='a') ++l1;
			else if(s1[j]=='a') ++r1;
			else flag = 0;
		}
		flag = 1;
		for(int j=0;s2[j];++j){
			if(flag&&s2[j]=='a') ++l2;
			else if(s2[j]=='a') ++r2;
			else flag = 0;
		}	
		b.emplace_back((node){l1,l2,r1,r2});
	}
	while(q--){
		cin>>t1>>t2;
		int flag = 1;
		ans = l1 = l2 = r1 = r2 = 0;
		for(int j=0;t1[j];++j){
			if(flag&&t1[j]=='a') ++l1;
			else if(t1[j]=='a') ++r1;
			else flag = 0;
		}
		flag = 1;
		for(int j=0;t2[j];++j){
			if(flag&&t2[j]=='a') ++l2;
			else if(t2[j]=='a') ++r2;
			else flag = 0;
		}
		for(const node& len : b){
			if(len.l1<=l1&&len.r1<=r1&&len.l1-len.l2==l1-l2&&len.r1-len.r2==r1-r2) ++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

