#include <iostream>
using namespace std;
int n,a[5005],ans;
inline void dfs(int now,int maxx,int sum,int sel){
	if(now==n+1){	
		if(sum>(maxx<<1)&&sel>=3)ans=(ans+1)%998244353; 
		return; 
	}
	dfs(now+1,max(maxx,a[now]),sum+a[now],sel+1);
	dfs(now+1,maxx,sum,sel);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<(ans>>1)%998244353;
}
