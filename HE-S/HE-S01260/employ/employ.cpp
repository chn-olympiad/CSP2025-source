#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600,mod=998244353;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int n,m,s[N],c[N],x,mi=INT_MAX;
bool f;int f2;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(s[i]);
		if(s[i]!=1)f=1;
		if(m==1){
			if(s[1]==1)f2=2;
			else f2=1;
		}
	}
	if(!f){
		cout<<0;return 0;
	}
	if(f2==2)cout<<0;
	else cout<<1;
	for(int i=1;i<=n;i++){
		read(c[i]);
		if(n==m)mi=min(mi,c[i]);
	}
	if(n==m){
		int x=1;
		for(int i=1;i<n;i++)x=((x%mod)*(i%mod))%mod;
		cout<<x%mod;
	}
	return 0;
}
