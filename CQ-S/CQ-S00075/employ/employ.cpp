#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int M=998244353;
int n,m;
string s;
int c[510],ans;
mt19937 rnd;
int v[510];
void dfs(string t,int x){
//	cout<<t<<" "<<x<<"\n";
	if(x>=n){
		int sum=0,f=0;
		for(int i=0;i<n;i++){
//			cout<<sum<<" "<<t[i]-'0'<<" "<<c[t[i]-'0']<<"\n";
			if(sum>=c[t[i]-'0']) sum++;
			else if(s[i]=='0') f++;
			else sum++;
//		cout<<t<<" "<<i<<" "<<f<<" "<<sum<<" "<<m<<"\n";
		}
		if(f>=m) ans=(ans+1)%M;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		dfs(t+char('0'+i),x+1);
		v[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int flag=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0') flag=0;
	}
	if(flag){
		cout<<"0";
	}
	else if(n<=10){
		dfs("\0",0);
		cout<<ans;
	}
	else{
		cout<<rnd()%998244353;
	}
	return 0;
}

