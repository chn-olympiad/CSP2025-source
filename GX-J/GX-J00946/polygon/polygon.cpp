#include<bits/stdc++.h>
using namespace std;
int n,f=0;
int a[5005];
int b[1000];
int c[10000];
int d[1000];
void dfs(long long zh,int zdz,int gs,int tail){
	
	if(gs>=3&&zh>zdz*2){
		if(b[zdz]==0||c[zh]==0||d[gs]==0){
			cout<<zh<<" "<<zdz<<" "<<gs<<endl;
		 f++;
		 b[zdz]=1;
		 c[zh]=1;
		 d[gs]=1;
	 }
	 }
	if(gs==n+1) return;
	for(int i=tail+1;i<=n;i++){
		int e=max(zdz,a[i]);
		dfs(zh+a[i],e,gs+1,i);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,1,1);
	cout<<f%998244353;
}
