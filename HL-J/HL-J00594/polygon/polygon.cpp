#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,a[5001],f=0,k=0;
void dfs(int i,long long e,long long m){
	if(i>3 && e>m*2) k++;
	if(i>n){
		f=1;
		cout<<k;
	}
	if(f==1) return;
	dfs(i+1,e+a[i],max(m,a[i]));
	dfs(i,e,m);
}
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	return 0;
}
