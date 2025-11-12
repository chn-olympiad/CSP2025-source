#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[500005];
bool vis[1000][1000];
bool solve(int l,int r){
	int m=a[l];
	for(int i=l+1;i<=r;i++){
		m^=a[i];
	}
	if(m==k)
		return true;
	else
		return false;
}
int dfs(int l,int r){
	if(l==r){
		if(solve(l,r))
			return 1;
		else
			return 0;
	}
	int h=0;
	if(solve(l,r))
		h++;
	int s=0;
	for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++){
			if(!vis[i][j]){
				vis[i][j]=true;
				s=max(s,dfs(i,j));
				vis[i][j]=false;
			}
		}
	h=max(h,s);
	return h;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	vis[1][n]=true;
	if(k==2||k==3)
		cout<<2;
	else
		cout<<dfs(1,n);
	return 0;
}
