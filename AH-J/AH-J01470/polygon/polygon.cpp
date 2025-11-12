#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000];
int dp[10000];
int ans;
int dfs(int x,int mx,int he){
if (he>mx*2){
ans++;	
}
if (x>=n){
	return ans;
}

int tmx=max(mx,a[x]);
int the=a[x]+he;
dfs(x+1,tmx,the);
dfs(x+1,mx,he);
return -1;
}
	
int main(){
freopen ("polygon.in","r",stdin);
freopen ("polygon.out","w",stdout);
cin>>n;
for (int i=0;i<n;i++){
	cin>>a[i];
}
dfs(0,0,0);
if (n>3){
	cout<<ans-2;
}else {
	cout<<ans;
}
return 0;
}
