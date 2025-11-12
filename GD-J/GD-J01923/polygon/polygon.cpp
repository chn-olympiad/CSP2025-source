#include<bits/stdc++.h>
using namespace std;
int a[5001],ans=0,n,sum;
const int p=998244353;
void dfs(int x,int step,int m){
	if(a[x]<step&&m>=2){
		ans++;
		ans%=p;
		//cout<<a[x]<<" "<<step+a[x]<<"\n";
	}
	if(x==n)return;
	dfs(x+1,step+a[x],m+1);
	if(n-x+1<3-m)return;
	dfs(x+1,step,m); 
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
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
