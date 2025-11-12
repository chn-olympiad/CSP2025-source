#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5010];
vector<int> path;
int ans=0;
int com(int up,int down){
	int cnt=1;
	int div=up;
	for(int i=down;i>=1;i--){
		cnt*=i;
		while(cnt%div==0 && div>=2){
//		cout<<cnt<<endl;
			cnt/=div;
			div--;
		}
		cnt%=998244353;
	}
	return cnt;
}
int solve(int t){
	if(t==n+2){
		if(path.size()<=2){
			return 0;
		}
		int sn=0;
		int mx=0;
		for(int i=0;i<path.size();i++){
			sn+=path[i];
//			cout<<path[i]<<" ";
			mx=max(mx,path[i]);
		}
		if(sn>2*mx){
			ans++;
			ans%=998244353;
		}
//		cout<<endl;
		return 0;
	}
	solve(t+1);
	path.push_back(a[t-1]);
	solve(t+1);
	path.pop_back();
	return 0;
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			ans+=com(i,n);
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	solve(2);
	cout<<ans<<endl;
	return 0;
}

