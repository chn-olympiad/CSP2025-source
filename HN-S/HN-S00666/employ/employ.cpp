#include<bits/stdc++.h>
using namespace std;
#define int long long	
int n,m,flag=1,pos=0,flag2=0;
const int mod = 998244353;
const int maxn = 5e2+7;
int lv[maxn],c[maxn];
int jiecheng(int x) {
	int sum=1;
	for(int i=2; i<=x; i++) {
		sum*=i;
		sum%=mod;
	}
	return sum;
}
int C(int n,int m) {
	return jiecheng(n)/jiecheng(m)/jiecheng(n-m);
}
int ans[maxn],vis[maxn];
int cnt=0;
bool check() {
	int luqu=0,fangqi=0;
	for(int i=1;i<=n;i++) {
		if(lv[i]==1) {
			if(c[ans[i]]>fangqi){
				luqu++;
			} else {
				fangqi++;
			}
		} else {
			fangqi++;
		}
	}
//	cout<<'\n';
	return luqu>=m;
}
void dfs(int pos) {
	if(pos>n) {
		if(check()) {
			cnt++;
			cnt%=mod;	
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			ans[pos]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	s='%'+s;
	for(int i=1; i<=n; i++) {
		lv[i]=s[i]-'0';
		if(lv[i]==0) {
			if(flag2==0) {
				pos++;
			}
			flag=0;
		} else {
			flag2=1;
		}
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	if(n<=18) {
		dfs(1);
		cout<<cnt<<'\n';
		return 0;
	} 
	if(flag==1) {
		cout<<jiecheng(n);
		return 0;
	}
	if(m==1) {
		for(int i=1; i<=n; i++) {
			if(c[i]>pos) {
				cnt++;
			}
		}
		int sum=1;
		for(int i=n-1; i>=1; i--) {
			sum*=jiecheng(i)%mod;
			sum%=mod;
		}
		int sum2=0;
		for(int i=1;i<=cnt;i++) {
			sum2+=(C(cnt,i)%mod)*(sum%mod)%mod;
			sum2=(sum2%mod+mod)%mod;
		}
		cout<<sum2<<'\n';
		return 0;
	}
	if(m==n) {
		if(flag==0) {
			cout<<0<<'\n';
		} else {
			cout<<1<<'\n';
		}
		return 0;
	}
	return 0;
}
