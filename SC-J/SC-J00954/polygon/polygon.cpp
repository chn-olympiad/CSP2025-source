#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5005],f[5005],n,ans;
void getans(){
	int sum,Max,cnt;
	sum=Max=cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			sum+=a[i];
			Max=max(Max,a[i]);
			cnt++;
		}
	}
	if(cnt<3)return ;
	if(Max*2>=sum)return ;
	ans++;
	ans%=998244353;
}
void dfs(int x){
	if(x>n){
		getans();
		return ;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}