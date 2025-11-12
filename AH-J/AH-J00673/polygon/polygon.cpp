#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100005];
int cnt;
void dfs(int idx,int sum,int maxn,int choose){
	if(idx==n+1){
		if(choose<3){
			return ;
		}else{
			if(maxn*2>=sum){
				return ;
			}else{
				cnt++;
			}
		}
		return ;
	}
	dfs(idx+1,sum,maxn,choose);
	dfs(idx+1,sum+a[idx],max(maxn,a[idx]),choose+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxv=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxv=max(maxv,a[i]);
	}
	if(maxv==1){
		cout<<(n-1)*(n-2)/2;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
}
