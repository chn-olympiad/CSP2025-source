#include <iostream>
#include <algorithm>
using namespace std;
int n,cnt;
int a[5005];
void dfs(int s,int Max,int sum,int num){
	if(s==n+1){
		if(num>=3&&sum>2*Max) cnt++;
		return ;
	}
	dfs(s+1,max(a[s],Max),sum+a[s],num+1);
	dfs(s+1,Max,sum,num);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,-1,0,0);
	cout<<cnt<<endl;
	return 0;
}
