#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010],ans;
void print(int x){
	if(x<=1) return;
	else{
		long long s=0,lo;
		for(int i=n;;i--){
			if(b[i]==1){
				lo=i;
				break;
			}
		}
		for(int i=1;i<=lo-1;i++){
			if(b[i]==1) s+=a[i];
		}
		if(s>a[lo]) ans=(ans+1)%998244353;
		return;
	}
}
void dfs(int lev,int js){
	if(lev>n){print(js); return;}
	b[lev]=1;
	dfs(lev+1,js+1);
	b[lev]=0;
	dfs(lev+1,js);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans%998244353; 
	return 0;
}
