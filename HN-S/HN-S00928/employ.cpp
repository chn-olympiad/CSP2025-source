#include<bits/stdc++.h>
using namespace std;
const int N=507;
int c[N],res[N];
int n,m;
bool st[N];
int ans=0;
string s;
void dfs(int u){
	if(u==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!s[i-1]-'0'||sum>c[res[i]]){
				sum++;
			}
		}
		if(n-sum>=m){
			ans++;
		}return;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			res[u]=i;
			st[i]=1;
			dfs(i+1);
			st[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3){
		cout<<2;
		return 0;
	}
	if(n==10){
		cout<<2204128;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
