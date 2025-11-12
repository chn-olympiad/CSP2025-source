#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ans;
void dfs(int t,int k){
	//k是现在的位置，t是还需的数
	if(t<0&&k==1){
		ans++;
		if(ans>=998244353)ans-=998244353;
	}
	if(k<=1)return;
	dfs(t-a[k-1],k-1);
	dfs(t,k-1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(a[i],i);
	}
	cout<<ans;
	return 0;
}