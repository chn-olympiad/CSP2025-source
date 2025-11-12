#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool bo[5005];
long long ans;
void dfs (int maxx,int o,long long k){
	if(a[o]+k>max(maxx,a[o])*2){
		ans++;
	}
	for(int i=1;i<o;i++){
		dfs(max(maxx,a[o]),i,k+a[o]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dfs(0,i,0);
	}
	cout<<ans;
	return 0;
}
