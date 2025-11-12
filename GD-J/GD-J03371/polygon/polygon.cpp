#include<bits/stdc++.h>
using namespace std;
int n,out=0;
vector<int>a;
void dfs(int now_i,int now_add){
	if(now_i>=n)return;
	if(now_add+a[now_i]>a[now_i]*2){
		out++;
		out%998244353;
	}
	dfs(now_i+1,now_add);
	dfs(now_i+1,now_add+a[now_i]);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	dfs(0,0);
	cout<<out;
	return 0;
}
//n is broken
