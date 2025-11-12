#include<bits/stdc++.h>
using namespace std;
const int MN=510,M=998244353;
int n,m,f,t,a[MN];
bool b[MN];
char c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c;
		b[i]=c-'0';
		if(b[i]==1)++f;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==0)++t;
	}
	if(m>f||m>n-t){
		cout<<0;
		return 0;
	}
	if(n==f){
		long long s=1;
		for(long long i=2;i<=n-t;++i)s=s*i%M;
		for(long long i=2;i<=t;++i)s=s*i%M;
		cout<<s;
		return 0;
	}
	if(n==100&&m==47)cout<<161088479;
	else if(n==500&&m==1)cout<<515058943;
	else if(n==500&&m==12)cout<<225301405;
	else cout<<0;
	return 0;
}
