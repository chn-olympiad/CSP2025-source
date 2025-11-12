#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100002],b[100002],c[100002],cnt[4],sum,ans;
multiset<int> p,q;
bool B(){
	for(int i=1;i<=n;i++) if(c[i]) return 0;
	return 1;
}
bool A(){
	if(!B()) return 0;
	for(int i=1;i<=n;i++) if(b[i]) return 0;
	return 1;
}
void dfs(int num,int x){
	if(num>n){
		ans=max(ans,x);
		return;
	}
	if(cnt[1]<sum){
		cnt[1]++;
		dfs(num+1,x+a[num]);
		cnt[1]--;
	}
	if(cnt[2]<sum){
		cnt[2]++;
		dfs(num+1,x+b[num]);
		cnt[2]--;
	}
	if(cnt[3]<sum){
		cnt[3]++;
		dfs(num+1,x+c[num]);
		cnt[3]--;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=n/2,ans=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		if(A()){
			sort(a+1,a+1+n);
			for(int i=n;i>sum;i--) ans+=a[i];
			cout<<ans<<'\n';
			continue;
		}
		else{
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}