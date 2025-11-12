#include<bits/stdc++.h>

using namespace std;
//Ren5Jie4Di4Ling5%
int n,m;
string s;
int a[100010],mo=998244353,kk,st[100010],k[1001];
void dfs(int u,int ss){
//	cout<<u<<' '<<ss<<"\n";
	
	/*
	3 2
	101
	1 1 2
	*/
	if(u==n+1){
		if(n-ss>=m){
			kk=(kk+1)%mo;
//			for(int i=1;i<=n;i++)cout<<k[i]<<' ';
//			cout<<"\n";
		}
		return;
	}
	if(n-ss<m)return;
	for(int i=1;i<=n;i++){
		if(st[i])continue;
		st[i]=1;
		k[u]=i;
		if(ss>=a[i])dfs(u+1,ss+1);
		else dfs(u+1,ss+(1-s[u-1]+'0'));
		st[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
	int f=1;
	for(int i=0;i<s.size();i++){
		f&=(s[i]=='0');
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
//	f=0;
	if(f){
		int su=1;
		for(int i=1;i<=n;i++){
			su=(su*i)%mo;
		}
		cout<<su;
		return 0;
	}
	dfs(1,0);
	cout<<kk<<' ';
	return 0;
} 
/*

6 3
111111
1 1 1 1 1 1
*/
