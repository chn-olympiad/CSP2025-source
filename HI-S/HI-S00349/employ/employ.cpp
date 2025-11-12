#include<bits/stdc++.h>
#include<set>
#define li 998244353 
#define ll long long
using namespace std;
set<ll> ss;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	string s;
	cin>>s;
	ll number=0,mark;
	bool flag=0;
	for(int i=0;i<s.size();++i) if(s[i]=='0'){
		flag=1;
		break;
	}
	if(flag) mark=0;
	else mark=1;
	flag=0;
	for(int i=0;i<s.size();++i) if(s[i]=='1'){
		flag=1;
		break;
	}
	if(!flag){
		printf("0");
		return 0;
	}
	if(n==m){
		ll num;
		for(int i=1;i<=m;++i){
			scanf("%lld",&num);
			ss.insert(num);
		}
		if(ss.size()==n&&mark==1) printf("%lld",m%li);
		else printf("0");
		return 0;
	}
	else{
		ll num;
		for(int i=1;i<=m;++i) scanf("%lld",&num);
		printf("0");
	}
return 0;
}

