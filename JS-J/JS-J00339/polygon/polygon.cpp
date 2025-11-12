#include<bits/stdc++.h>
using namespace std;
int a[5010],ls[5010];
int ans,n;
void check(int x){
	int ls_bf[5010];
	for(int i=1;i<=n;i++) ls_bf[i]=ls[i];
	sort(ls_bf+1,ls_bf+n+1,greater<int>());
	int sum=0;
	for(int i=2;i<=x;i++) sum+=ls_bf[i];
	if(sum>ls_bf[1]) ans++;
	return ;
}
void dfs(int x,int st,int xbf){
	int stb=st;
	if(x==0){ 
		check(xbf);
		x++;
		st=stb;
		ls[st]=0;
		return ;
	}
	for(int i=st;i<=n-x+1;i++){
		ls[st]=a[i];
		x--;
		st=i+1;
		dfs(x,st,xbf);
		x++;
		st=stb;
		ls[st]=0;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) dfs(i,1,i);
	ans=ans%998244353;
	cout<<ans;
	return 0;
}
