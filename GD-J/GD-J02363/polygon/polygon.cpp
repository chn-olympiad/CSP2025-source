#include<bits/stdc++.h>
using namespace std;
int a[5010],ans,n;
void dfs(int no,int sum,int maxp,int bs){
	if(bs+(n-no+1)<3)return;
	if(no==n+1){
		if(bs<3)return;
		if(sum<=maxp*2)return;
		ans++;
		return;
	}
	dfs(no+1,sum+a[no],max(maxp,a[no]),bs+1);
	dfs(no+1,sum,maxp,bs);
	return;
}
int main(){
	freopen("r","polygon.in",stdin);
	freopen("w","polygon.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
