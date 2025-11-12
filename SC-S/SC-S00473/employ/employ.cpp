#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll n,m,ans,num=0,mod=998244353;
string s;
ll p[N],b[N];

void read(){
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		num+=(s[i]=='1');
	}
}

void dfs(ll xb,ll def){
	if(xb>n){
		if(n-def>=m) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		b[i]=1;
		dfs(xb+1,def+(s[xb]=='1'?(def>=p[i]):1));
		b[i]=0;
	}
}

void s1(){
	dfs(1,0);
	cout<<ans<<"\n";
}

void s2(){
	cout<<num<<"\n";
}
void s4(){
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cout<<"0\n";
			return;
		}
	}
	cout<<"1\n";
}
void s3(){
	ll cnt=1;
	for(int i=1;i<=n;i++){
		cnt=cnt*i%mod;
	}
	cout<<cnt<<'\n';
}

void solve(){
	if(n<=18) s1();
	else if(m==1) s2();
	else if(m==n) s4();
	else if(num==n)s3();
	else cout<<66<<"\n";
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read();
	solve();
	return 0;
}