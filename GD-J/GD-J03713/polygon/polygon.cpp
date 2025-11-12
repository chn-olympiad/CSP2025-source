#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5000+23];
int ans;
int t[5000+23];
void dfs(int pos,int tot){
	int sum=0;
	for(int i=1;i<tot;i++)	sum+=a[t[i]];
	if(sum>a[t[tot]]){
		ans++; 
		//for(int i=1;i<=tot;i++)	cout<<a[t[i]]<<' ';
		//cout<<endl;
	}
	if(pos>n)	return;
	for(int i=t[tot]+1;i<=n;i++){
		t[tot+1]=i;
		dfs(pos+1,tot+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<ans;
	return 0;
}
