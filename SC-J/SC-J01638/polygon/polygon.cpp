#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,cnt,ii;
void dfs(int x,int y,int sum,int z){
//	cout<<sum<<' '<<z<<' '<<'\n';
	if(z==0&&sum>a[ii]) cnt=(cnt+1)%998244353; 
	for(int i=y+1;i<=x;i++){
		z--;
		dfs(x,i,sum+a[i],z);
		z++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3&&(a[1]+a[2]+a[3])>(2*maxn)){
		cout<<1;
		return 0;
	}
	if(n==3&&(a[1]+a[2]+a[3])<=(2*maxn)){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=2;j<=i-1;j++){
			ii=i;
			dfs(j,0,0,j);
		}
	}
	cout<<cnt%998244353;
//	dfs(3,0,0,3);
//	cout<<cnt;
	return 0;
}