#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=505;
int n,m,s[N],c[N],f,t,tt=-1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
		if(s[i]==1) f++;
	}
	if(f<m){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) t++;
		if(c[i]==1) tt++;
	}
	if(tt==-1) tt=0;
	if(n-tt-t<m){
		printf("0");
		return 0;
	}
	ll ans=1;
	for(int i=1;i<=n-tt-t;i++){
		ans=ans*i%998244353;
	}
	printf("%lld",ans);
	return 0;
}

