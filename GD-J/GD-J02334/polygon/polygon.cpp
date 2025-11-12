#include<bits/stdc++.h>
using namespace std;
int n,s[5050],cnt,t;
void dfs(int step,int maxx,int sn,int sum){
	t++;
	if(t>100000000)return;
	if(step==n+1){
		if(maxx>=0&&sn>=3&&maxx*2<sum){
			cnt++;
		}
		return;
	}
	dfs(step+1,max(maxx,s[step]),sn+1,sum+s[step]);
	dfs(step+1,maxx,sn,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dfs(1,-1e9,0,0);
	cout<<cnt;
}
