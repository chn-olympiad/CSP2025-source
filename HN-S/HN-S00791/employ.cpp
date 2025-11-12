#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define ull unsigned long long
#define max3(a,b,c) max(a,max(b,c))
#define fi first
#define se second

using namespace std;
const int N=5e5+5;
const int mod=998244353;
inline int in(){
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0'; c=getchar();
	}return s*w;
}
int n,m,c[N];
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'==1) sum++;
	}
	ll dfg=1,g=1,fg=1;
	for(int i=2;i<=m;i++){
		g=(g*i)%mod;
	}
	for(int i=2;i<=n;i++){
		dfg=(dfg*i)%mod;
	}
	for(int i=2;i<=n-m;i++){
		fg=(fg*i)%mod;
	}
	cout<<dfg/(g*fg);
	return 0;
}
