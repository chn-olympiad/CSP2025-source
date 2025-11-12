#include<iostream>
#include<algorithm>
using namespace std;
int a[5000];
int n;
int ans=0;
void dfs(int f,int s,int v,int sum){
	if(s>f){
		if(sum>a[v-1]*2){
			ans++;
		}
		return;
	}
	for(int i=v;i<n;i++){
		dfs(f,s+1,i+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		dfs(i,0,0,0);
	}
	cout<<ans%998244353;
	return 0;
}