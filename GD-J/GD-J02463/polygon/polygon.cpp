#include<bits\stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],anss,bb1,vis[5005];
void dfs(int summ,int mx,int nww,int css){
	if(nww>n){
		if(summ>2*mx and css>=3){
			anss++;
			anss%=mod; 
		}return;
	}dfs(summ+a[nww],max(mx,a[nww]),nww+1,css+1);
	dfs(summ,mx,nww+1,css);
}int zuh(int m){
	int hh1=1;
	for(int i=1;i<=m;i++)vis[i]=0;
	for(int i=n;i>=n-m+1;i--){
		hh1*=i;
		for(int j=1;j<=m;j++){
			if(!vis[j] and hh1%j==0){
				vis[j]=1;
				hh1/=j;
			}
		}hh1%=mod;
	}return hh1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)bb1=1;
	}if(bb1==0 and n>25){
		for(int i=3;i<=n;i++){
			if(n-i>i)anss+=zuh(i);
			else anss+=zuh(n-i);
			anss%=mod;
		}cout<<anss;
		return 0;
	}
	dfs(0,0,1,0); 
	cout<<anss;
	return 0;
} 
