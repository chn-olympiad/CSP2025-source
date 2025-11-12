#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,ans;
int a[5005];
bool st[5005];

bool f(){
	int sum=0,mx=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(st[i]){
			mx=max(mx,a[i]);
			sum+=a[i];
			cnt++;
			//cout <<i<<" ";
		}
	}
	//cout <<mx<<'\n';
	if(cnt<3)return 0;
	if(sum>mx*2)return 1;
	return 0;
}

void dfs(int now){
	if(now==n+1){
		if(f()){
			ans++;
			//cout <<ans<<"\n";
		}
		return ;
	}
	dfs(now+1);
	st[now]=1;
	dfs(now+1);
	st[now]=0;
	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3]){
			cout <<1;
		} else cout <<0;
		
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1);
	cout <<ans;
	
	return 0;
}
