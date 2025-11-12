#include<bits/stdc++.h>
using namespace std;
int n,a[5055],ans;
void dfs(int sx,int sum,int bg,int num,int last){
	if(num==sx){
		if(sum>2*bg){
			++ans;
			ans%=998244353;
		}
		return;
	}
	for(int i=last+1;i+(sx-num)-1<=n;i++){
		dfs(sx,sum+a[i],max(bg,a[i]),num+1,i);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,0);
	}
	cout<<ans;
	return 0;
}