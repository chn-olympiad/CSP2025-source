#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool b[5005];
void dfs(int x,int s,int h,int v){
	if(s==0&&h>a[x]){
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=v-1;i>0;i--){
		dfs(x,s-1,h+a[i],i);
	}
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
	for(int i=3;i<=n;i++){
		for(int j=3;j<=n;j++){
			dfs(j,i-1,0,j);
		}
	}
	cout<<ans;
	return 0;
}
