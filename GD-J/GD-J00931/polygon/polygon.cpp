#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5020];
bitset<5020> vis;
int s[5020];
int ans;
int dpow(int t){//quick 2^t
	int r=1,m=2;
	while(t){
		if(t&1){
			r=(1ll*r*m)%mod;
		}
		t>>=1;
		m=(1ll*m*m)%mod;
	}
	return r;
}
void dfs(int depth,int last,int c,int sum,int ma){
	if(depth>c){
		if(sum>2*ma){
			ans=(ans+1)%mod;
		}
		return;
	}
	//if max cannot get 2ma,return
	if(sum+s[c-depth+1]<=2*ma){
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(depth+1,i,c,sum+a[i],max(ma,a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(f){
		//cout<<dpow(n)<<"\n"<<n<<"\n"<<(1ll*n*(n-1)/2)<<"\n";
		cout<<(dpow(n)-n-(1ll*n*(n-1)/2)-1);
		return 0;
	}
	sort(s+1,s+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,i,0,0);
	}
	cout<<ans;
	return 0;
}
