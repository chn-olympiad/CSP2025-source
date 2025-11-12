#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],ans;
bool flg[5005];
void dfs(int stp,int h,ll mx){
	if(stp>=3&&(h>(mx*2))){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flg[i]){
			flg[i]=1;
			dfs(stp+1,h+a[i],max(mx,a[i]));
			flg[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans%998244353<<endl;
}
