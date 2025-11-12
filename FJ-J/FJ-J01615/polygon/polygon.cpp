#include<bits/stdc++.h>
using namespace std;
int n;
int st[5050];
int qzh[5050];
int cnt=0;
void dfs(int s,int x,int w,int nnmm){
	if(nnmm>=3 && s>x*2) cnt++;
	for(int i=w+1;i<=n;i++)
		dfs(s+st[i],max(x,st[i]),i,nnmm+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&st[i]);
	dfs(0,0,0,0);
	cout<<cnt;
	return 0;
}
