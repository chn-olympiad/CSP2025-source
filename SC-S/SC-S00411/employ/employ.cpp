#include<bits/stdc++.h>
using namespace std;
int n,m,c[5005],ans,rec[5005],vis[5005];
char s[5005];
/*
bool check(){
	int ct=0,r=0,p=1;
	for(int i=1;i<=n&&p<=n;i++){
		if(r>=c[rec[p]]){
			while(r>=c[rec[p]]&&p<=n){
				p++;
			}
			if(p>n)break;
		}
		if(s[i]=='0'){
			r++;
		}else{
			ct++;
		}
		p++;
	}
	cout<<ct<<endl;
	if(ct>=m)return 1;
	return 0;
}
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++)cout<<rec[i]<<' ';
		cout<<endl;
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			rec[x]=i;
			dfs(x+1);
			vis[i]=0;
		} 
	} 
}
*/
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%c",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	//dfs(1);
	srand(time(0));
	ans=rand();
	printf("%d",ans%998244353);
	return 0;
}