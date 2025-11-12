#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
const int P=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	vi s(n+1);
	bool xz1=true;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		s[i]=c-'0';
		if(s[i]!=1)xz1=false;
	}
	vi c(n+1);
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt0++;
	}
	vi p(n+1);
	iota(p.begin(),p.end(),0);
	ll ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||!s[i])cnt++;
		}
		//dbe(cnt);
		//for(int i=1;i<=n;i++)cerr<<p[i]<<" \n"[i==n];
		if(n-cnt>=m)ans++;
	}while(next_permutation(p.begin()+1,p.end()));
	cout<<ans%P<<endl;
	return 0;
}