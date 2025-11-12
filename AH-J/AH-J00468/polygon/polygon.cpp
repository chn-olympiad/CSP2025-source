#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5003];
int f[2][10004];
int m=0;
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	return;
}
void work(){
	f[0][0]=1;
	for(int i=1;i<=2;i++){
		for(int j=0;j<=m;j++){
			f[i%2][j]=f[(i-1)%2][j];
		}
		for(int j=0;j<=m;j++){
			f[i%2][min(10001,j+a[i])]+=f[(i-1)%2][j];
			f[i%2][min(10001,j+a[i])]%=mod;
		}
		m=min(m+a[i],10001);
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i%2][j]=f[(i-1)%2][j];
		}
		for(int j=a[i]+1;j<=m;j++){
			ans+=f[i%2][j];
			ans%=mod;
		}
		for(int j=0;j<=m;j++){
			f[i%2][min(10001,j+a[i])]+=f[(i-1)%2][j];
			f[i%2][min(10001,j+a[i])]%=mod;
		}
		m=min(m+a[i],10001);
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t;
	//~ scanf("%d",&t);
	t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
