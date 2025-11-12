#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],su,b[5005];
bool bo=1;
long long jc(int y,int z){
	long long s=1;
	for(int i=y-z+1;i<=y;i++) s*=i;
	for(int i=2;i<=z;i++) s/=i;
	return s;
}
long long f(int x,int m){
	if(m==x+1){
		int fma=0;
		for(int fi=2;fi<=x;fi++) fma+=a[b[fi]];
		if(a[b[1]]<fma) return 1;
		else return 0;
	}
	long long fs=0;
	for(int fi=b[m-1]+1;fi<n-x+m;fi++) b[m]=fi,fs+=f(x,m+1);
	return fs;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) bo=0;
	}
	sort(a,a+n,greater<long long>());
	b[0]=-1;
	if(bo) for(int j=3;j<=n;j++) su+=jc(n,j),su%=998244353;
	else for(int j=3;j<=n;j++) su+=f(j,1),su%=998244353;
	cout<<su<<endl;
	return 0;
}
