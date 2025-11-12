#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],ans;
void dfs(int mx,int sum,int now){
	if(now==n+1){
		if(sum>mx*2)ans=(ans+1)%998244353;
		return;
	}
	dfs(mx,sum,now+1);
	mx=max(mx,a[now]);
	sum+=a[now];
	dfs(mx,sum,now+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,1); 
	cout<<ans<<"\n";
	return 0;
}
//10:26 Ð´ÍêÁË£¬100+100+50+50=300(?) 

