#include<bits/stdc++.h>
using namespace std;
const int N =5e3+10;
int a[N],n,sum;
int ans;
void dfs(int i,int sum,int cnt){
	if(i>n)	return ;
	if(cnt>=3&&sum<a[i]*2)	ans++;
	if(cnt<=n){
		dfs(i+1,sum+a[i],cnt+1);
		dfs(i+1,sum,cnt);
	}
}
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
}
