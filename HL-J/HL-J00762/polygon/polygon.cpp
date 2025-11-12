#include<bits/stdc++.h>
using namespace std;
int n,k,a[5001],b[1001];
long long ansn;
int dfs(int x,int z){
	if(z==0){
		return a[x];
	}for(int i=x+1;i<=n;i++){
		b[z]=dfs(i,z-1);
		//cout<<b[z]<<" "; 
		int sumn=0,maxn=0;
		for(int j=1;j<=z;j++){
			sumn+=b[j];
			maxn=max(maxn,b[j]);
		}if(sumn>maxn*2){
			ansn++;
			ansn%=998244353;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3] && max(a[1],a[2])-min(a[1],a[2])<a[3]){
			cout<<1;
		}else{
			cout<<0;
		}return 0;
	}
	for(int m=3;m<=n;m++){
		for(int i=1;i<=n-m;i++){
			dfs(i,m);
		}
	}cout<<ansn%998244353;
	return 0;
}
