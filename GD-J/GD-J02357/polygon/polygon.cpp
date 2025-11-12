#include<iostream>
#include<algorithm> 
using namespace std;
int l[5010],n,ans,add;
void dfs(int maxp){
	for(int i=maxp;i<=n&&add>l[i];i++){
		ans++;
	}
	ans%=998244353;
	for(int i=maxp;i<n;i++){
		add+=l[i];
		dfs(i+1);
		add-=l[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	sort(l+1,l+n+1);
	dfs(1);
	cout<<ans;
}
