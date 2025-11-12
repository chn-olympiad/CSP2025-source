#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans=0;
void fun(int m,int o,int maxx,int total){
	//if(m>=3 && total<=maxx*2) return;
	//cout<<'*'<<m<<' '<<total<<' '<<maxx<<'\n';
	if(m>=3 && total>maxx*2) {
		ans++;
		ans%=998244353;
	}
	for(int i=o+1;i<=n;i++)
		fun(m+1,i,max(maxx,a[i]),total+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		fun(1,i,a[i],a[i]);
	}
	printf("%lld",ans);
	
	return 0;
}

