#include<bits/stdc++.h>
using namespace std;
int n,a[5009];
unsigned int long long ans=0,t=0;
const int mod=998244353;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int st,int mx,int ll,int s){
	if(st==1){
		for(int i=1;i<=n;i++){
			dfs(2,mx,i+1,-a[i]);
		}
		return;
	}if(st>mx){
		if(s>0){
			t++;
		}
		return;
	}
	for(int i=ll;i<=n;i++){
		dfs(st+1,mx,i+1,s+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[3]+a[2]>a[1]){
			putchar('1');
			return 0;
		}else{
			putchar('0');
			return 0;
		}
	}
	if(n<=20){
		for(int i=3;i<=n;i++){
			t=0;
			dfs(1,i,1,0);
			ans=(ans+(t%mod))%mod;
		}
		printf("%llu",ans);
		return 0;
	}
	printf("0");
	return 0;
}
