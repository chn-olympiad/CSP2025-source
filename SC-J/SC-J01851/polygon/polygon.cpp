#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
int a[5005];
void dfs(int now,int da,int ma){
	if(now>n){
		if(da>ma*2){
			cnt++;
			
		}
		return;
	}
	dfs(now+1,da,ma);
	da=da+a[now];
	if(a[now]>ma){
		ma=a[now];
	}
	dfs(now+1,da,ma);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}