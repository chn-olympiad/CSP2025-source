#include<bits/stdc++.h>
using namespace std;

const int N=510,mod=998244353;
int n,m;
string s;
int c[N];

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	int sl=0,ss=0;
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') {
			sl++;
			f=1;
		}
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(c[i]<=ss) ss++;
	}
	
	if(n-sl-ss<m){
		cout<<0<<"\n";
		return 0;
	}
	if(m==1){
		n-=ss;
		cout<<n<<"\n";
		return 0;
	}
	if(!f){
		int sl=0;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			if(c[i]==0) sl++;
		}
		n-=sl;
		if(n<m){
			cout<<0<<"\n";
			return 0;
		}
		long long res=1;
		for(long long i=1;i<=n;i++){
			res=res*i%mod;
		}
		cout<<res<<"\n";
		return 0;
	}
	
	return 0;
}
