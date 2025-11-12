#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5006],n;
long long h=0,z=0;
void dfs(int l,int h,int i,int mx){
	if(h>mx*2&&l>=3){
		z++;
	}
	for(int j=i;j<=n;j++){
		dfs(l+1,h+a[j],j+1,max(mx,a[j]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,0);
	if(z%2){
		z=z/2+1;
	}
	else{
		z=z/2;
	}
	z%=mod;
	printf("%lld",z);
	return 0;
}
