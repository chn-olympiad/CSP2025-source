#include <bits/stdc++.h>
using namespace std;
int n;
int a[5001]; 
long long ans=0;
long long jcs(int x,int y){
	long long s=1;
	for(int j=y+1;j<=x;++j){
		s*=j;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;++i){
		ans+=jcs(n,i);
	}
	ans%=998244353;
	printf("%lld",ans);
	return 0;
}

