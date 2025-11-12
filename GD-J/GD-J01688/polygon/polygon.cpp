#include<bits/stdc++.h>
using namespace std;
int n,ns[5005];
long long ans;
void dfs(int now,int zh,int ma,int cs){
	if(cs>=3&&zh>ma*2){
		ans++;
		ans%=998244353;
	} 
	for(int i=now+1;i<n;i++){
		dfs(i,zh+ns[i],max(ma,ns[i]),cs+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ns[i];
	}
	dfs(-1,0,0,0);
	cout<<ans;
	return 0;
} 
