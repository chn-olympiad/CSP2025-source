#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
long int cnt=0;
int b[100005];
int sum[100005];
void dfs(int m,int x){
	int Nm=m+1;
	int Nx=x+1;
	while(Nm<=n&&Nx<=n){
		b[x+1]=a[Nm];
		sum[x+1]=sum[x]+b[x+1];
		dfs(Nm,Nx);
		Nm++;
	}
	if(x>2&&x<=n){
		if(sum[x]>b[x]*2) cnt++;
	}
	return;
}
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int xx=n-2;
	for(int i=1;i<=xx;i++){
		b[1]=a[i];
		sum[1]=b[1];
		dfs(i,1);
	}
	long int temp=cnt;
	if(cnt>=998244353) temp=cnt%998244353;
	cout<<temp;
	return 0;
}
