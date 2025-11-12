#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int c[5001];
long long sss=0;
void dfs(int u,int t,int x){
	if(x==t){
		long long s=0;
		int maxs=0;
		for(int i=1;i<=x;i++){
			s+=a[c[i]];
			maxs=max(maxs,a[c[i]]);
		}
		if(s>maxs*1ll*2){
			sss++;
			sss%=998244353;
		}
		return;
	}
	for(int i=u+1;i<=n-(t-x)+1;i++){
		c[x+1]=i;
		dfs(i,t,x+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0);
	}
	cout<<sss;
	return 0;
}
