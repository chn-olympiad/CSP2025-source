#include<bits/stdc++.h>
using namespace std;
int n,l[5005],ans=0;
void dfs(int h,int x,int d,int c){
	if(x==h && c>l[d]*2){
		ans++;
		return;
	}for(int i=d+1;i<n;i++) dfs(h,x+1,i,c+l[i]);
	return;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>l[i];
	sort(l,l+n);
	for(int i=3;i<=n;i++) dfs(i,0,-1,0);
	cout<<ans;
	return 0;
}
