#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
int c[505];

void bf(){
	int x[505],ans=0;
	for(int i = 1; i<=n; i++) x[i]=i;
	do{
		int cnt=0;
		for(int i = 1; i<=n; i++){
			if(i-1-cnt>=c[x[i]]) continue;
			if(s[i-1]=='1') cnt++;
			if(n-i+cnt<m) break;
		}
		ans+=(cnt>=m);
	}while(next_permutation(x+1,x+1+n));
	cout<<ans%998244353;
}	

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i = 1; i<=n; i++) cin>>c[i];
	bool tag=true; for(auto ch:s) tag&=(ch=='1');
	if(tag){ //20 pts
		long long ans=1,d=0;
		for(int i = 1; i<=n; i++) d+=(!c[i]);
		for(int i = 2; i<=n-d; i++) ans=(ans*i)%998244353;
		return printf("%lld",ans), 0;
	}
	if(n<=10/*8 pts*/) return bf(), 0;
	return 0;
}
