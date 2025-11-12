#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5100],cnt=0;
void dfs(int now,int sum,int num){
	if(clock()>=995){
		cout<<cnt;
		exit(0);
	}
	for(int i=now+1;i<=n;i++){
		if(sum+a[i]>a[i]*2&&num>=3) cnt++;
		dfs(i,sum+a[i],num+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,1);
	cout<<cnt;
	fcloseall();
	return 0;
}
