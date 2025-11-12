#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5001];
void dfs(int i,int an,int max1,int step){
	for(int j=i+1;j<=n;j++){
		int tan=an+a[j],tmax=max(max1,a[j]),tstep=step+1;
		if(tan>tmax*2&&tstep>=3)ans++;
		dfs(j,an+a[j],max(max1,a[j]),step+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
