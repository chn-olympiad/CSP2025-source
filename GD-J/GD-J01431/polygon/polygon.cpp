#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],m,t[5005],ans;
void check(){
	int sum=0;
	for(int i=1;i<=m;i++)
		sum+=t[i];
	if(t[m]*2<sum)
		ans++,ans%=mod;
}
void dfs(int i,int k){
	if(m==k){
		check();
		return ;
	}
	for(int j=i;j<=n;j++){
		t[++m]=a[j];
		dfs(j+1,k);
		m--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
		dfs(1,i); 
	cout<<ans;
	return 0;
}
