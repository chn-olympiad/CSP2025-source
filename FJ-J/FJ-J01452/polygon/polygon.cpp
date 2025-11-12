#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];
long long sum[8888888];
int maxn;
int m[8888888];
int f;
int x;
void dfs(int k,int num){
	f++;
	sum[f]=num;
	m[f]=maxn;
	if(k==n){
		return;
	}
	for(int i=k+1;i<=n;i++){
		if(a[i]>=maxn){
			maxn=a[i];
		}
		dfs(i,num+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		maxn=a[i];
		dfs(i,a[i]);
	}
	for(int i=1;i<=f;i++){
		if(sum[i]>(m[i]*2)){
			x++;
		}
	}
	cout<<x;
	return 0;
}
