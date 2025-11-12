#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[100];
int b[100];
bool vis[100];
bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||sum>=b[i]){
			sum++;
		}
	}
	if(n-sum>=m){
		return 1;
	}
	else return 0;
}
int dfs(int deep){
	int sum=0;
	if(deep==n+1){
		return check();
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			cout<<i<<' '<<vis[i]<<'\n';
			b[deep]=a[i];
			sum+=dfs(i+1);
			vis[i]=0;
		}
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1);
	return 0;
}
/*
3 2
101
1 1 2
*/
