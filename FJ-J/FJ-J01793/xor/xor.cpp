#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
const int N=500005;
int n,k,cnt,a[500010],b[500010],c[500010];
int dp[500010],ans,tree[500010],len[500010];
vector<int> d[500010];
map<int,int> mp;
int lowbit(int x) {
	return x&(-x);
}
void add(int x,int d) {
	while(x<=N) {
		tree[x]=max(tree[x],d);
		x+=lowbit(x);
	}
}
int getsum(int x) {
	int ans=0;
	while(x>0) {
		ans=max(ans,tree[x]);
		x-=lowbit(x);
	}
	return ans;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	for(int i=n;i>=1;i--) {
		c[i]=c[i+1] xor a[i];
	}
	for(int i=1;i<=n+1;i++) {
		if(mp[c[i]]==0) {
			mp[c[i]]=++cnt;
		}
		d[mp[c[i]]].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		int sum=k xor c[i];
		int sum1=mp[sum];
		while(len[sum1]<d[sum1].size() && d[sum1][len[sum1]]<=i) {
			len[sum1]++;
		}
		if(len[sum1]<d[sum1].size()) {
			b[i]=d[sum1][len[sum1]]-1;
		}
	}
	dp[1]=(b[1]>0?1:0);
	if(b[1]>0) add(b[1],dp[1]);
	else add(1,dp[1]);
	for(int i=2;i<=n;i++) {
		dp[i]=getsum(i-1)+(b[i]>0?1:0);
		if(b[i]>0) add(b[i],dp[i]);
		else add(1,dp[i]);
	}
	for(int i=1;i<=n;i++) {
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}
