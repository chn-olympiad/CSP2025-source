#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],c,ans,e[5005],f[5005];//d[30]={0,0,0,1,5,16,42,99,219,466,968,1981,4017,8100,16278,32647,65399,130918,261972,524097,1048365};
int xuan(long long x,long long s){
	if(x==1){
		if(s>c)return 2;
		else if(s+a[x]>c)return 1;
		else return 0;
	}
	return (xuan(x-1,s+a[x])+xuan(x-1,s))%998244353;
}
void tui(){
	for(int i=1;i<n;i++){
		e[i]=e[i-1]+i;
	}
	for(int i=1;i<n;i++){
		e[i]+=e[i-1];
	}
	for(int i=1;i<n;i++){
		e[i]+=f[i-1];
		e[i]=e[i]%998244353;
		f[i]=f[i-1]+e[i];
		f[i]=f[i]%998244353;
	}
	cout<<e[n-2];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)c=1;
	}
	if(c==0){
		tui();
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){	
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		if(b[i-1]<=a[i])continue;
		c=a[i];
		ans+=xuan(i-1,0);
	}
	cout<<ans;
	return 0;
} 
