#include<bits/stdc++.h>
using namespace std;

int y=0;
long long n,a[10000],z=1,k=1,m=1,v=3,b[10000],s=0;

void dfs(long long g,long long h,long long d,long long gg){
	if(g==v){
		if(h>d*2){
			s++;
			s=s%998244353;
		}
		return;
	}
	for(long long t=gg;t<=n;t++){
		dfs(g+1,h+a[t],d=max(d,a[t]),t+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			y=1;
		}
	}
	if(n==3){
		if((a[1]+a[2])>a[3]&&(a[1]+a[3])>a[2]&&(a[2]+a[3])>a[1]){
			n=1;
			cout<<n;
			return 0;
		}
		else{
			n=0;
			cout<<n;
			return 0;
		}
	}
	if(y==0){
		for(long long i=1;i<=n;i++){
			k+=m;
			z*=2;
			z=z%998244353;
			m++;
		}
		cout<<z-k;
		return 0;
	}
	for(;v<=n;v++){
		dfs(0,0,-1,1);
	}
	cout<<s;
	return 0;
}
