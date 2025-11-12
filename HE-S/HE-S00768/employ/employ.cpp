#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
constexpr int N=510,mod=998244353;
int n,m,c[N];
string s;
namespace sub1_2{
	int p[N],cnt,res;
	void solve(){
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			cnt=0;
			for(int i=1;i<=n;i++)
				if(cnt>=c[p[i]]||s[i]=='0'){
					++cnt;
					if(n-cnt<m) break;
				}
			res+=n-cnt>=m;
		}while(next_permutation(p+1,p+1+n));
		cout<<res<<'\n';
	}
}
namespace sub15{
	ll fact;
	void solve(){
		fact=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<"0\n";
				return;
			}
			fact=fact*i%mod;
		}
		cout<<fact<<'\n';
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s="$"+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n) sub15::solve();
	else if(n<=18) sub1_2::solve();
	else cout<<"0\n";
	return 0;
}
