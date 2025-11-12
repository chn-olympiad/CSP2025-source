#include<bits/stdc++.h>
#define int long long
using namespace std;
int fdh[5005],ans=0,n;
void dfs(int x,int sum,int mx,int num){
	if(x>n){
		if(sum>2*mx&&num>=3){
			ans=(ans+1)%998244353;
			//cout<<sum<<" "<<mx<<endl;
		}
		return ;
	}
	dfs(x+1,sum+fdh[x],max(mx,fdh[x]),num+1);
	dfs(x+1,sum,mx,num);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>fdh[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 