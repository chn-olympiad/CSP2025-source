#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5001],cnt;
long long ans;
void dfs(int x,int y,int i){
	ans++;
	if(y==3) return;
	while(1){
		i++;
		if(x-a[i]<0) break;
		dfs(x-a[i],y-1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cnt+=a[1]+a[2];
	for(int i=3;i<=n;i++){
		if(cnt>a[i]) dfs(cnt-a[i]-1,i,0);
		cnt+=a[i];
		ans%=998244353;
	}
	cout<<ans;
}
