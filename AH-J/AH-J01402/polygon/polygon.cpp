#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans;
void dfs(int mx,int i,int sum,int q){
	if(i>n){
		if(sum>2*mx)ans++;
		//cout<<mx<<' '<<sum<<' '<<q<<'\n';
		return ;
	}
	dfs(max(mx,a[i]),i+1,sum+a[i],q++);
	dfs(mx,i+1,sum,q);
	//cout<<1;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0,0);
	cout<<ans;
    return 0;
}
//shebanghaoshan,baixiesheban
