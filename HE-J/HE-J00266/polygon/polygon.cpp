#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<vector> 
#include<cmath>
using namespace std;
priority_queue<int> q;
int n;
int qzh[5000+5];
int a[5000+5];
int cnt;
int b[5000+5];
void dfs(int cur,int k,int pos,int sum){
	if(pos>n){
		return;
	}
	if(cur>=n+2){
		return;
	}
	if(sum>k){
		cnt++;
	}
	for(int i = pos;i<=n;i++){
		dfs(cur+1,k,i+1,sum+=a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	int ans;
	for(int i = 0;i<n;i++){
		cin>>ans;
		q.push(ans);
	}
	for(int i = 1;i<=n;i++){
		qzh[i] = qzh[i-1]+q.top();
		a[i] = q.top();
		q.pop();
	}
	for(int i = 1;i<=n-2;i++){
		dfs(0,a[i],i+1,0);
	}
	cout<<cnt;
	return 0;
}
