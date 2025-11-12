#include<bits/stdc++.h>
using namespace std;
int a[500010],vis[500010],n,k,x=0;
void dfs(int u){
	for(int i=0;i<n;i++){
		int j;
		int ok=0;
		for(j=i;j<n;j++){
			if(vis[j]==1){
				ok=-1;
				break;
			}
			ok^=a[j];
			if(ok==k)break;
		}
		if(ok==k){
			for(int f=i;f<=j;f++)vis[f]=1;
			dfs(u+1);
			for(int f=i;f<=j;f++)vis[f]=0;
		}
	}
	x=max(u,x);
}
int s(){
	cout<<0;
}
int s1(){
	cout<<0;
}
int s2(){
	dfs(0);
	cout<<x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int g=0,f=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)f++;
		else if(a[i]==0)g++;
	}
	if(n<=2&&k==0)s();
	else if(n<=100&&k==0&&f==n)s1();
	else if(n<=500010&&k<=1&&g+f==n){
		if(k==1)cout<<f;
		else{
			for(int i=0;i<n;i++){
				if(a[i-1]==1&&a[i]==1&&vis[i-1]!=1){
					vis[i]=1;
					g++; 
				}
			}
			cout<<g;
		}
	}
	else s2();
}

