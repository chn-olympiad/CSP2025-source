#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void read(int &x){
	char c=getchar();x=0;
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-48,c=getchar();
}
void write(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>=10) write(x/10);
	putchar((char)(x%10+48));
}
const int N=5e5+5,M=(1<<20)+5;
ll a[N],n,m,yh[N],tmp,dp[N],maxx,zs;
vector<int> bj[M];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=1000) {
		for(int i=1;i<=n;i++){
			ll sum=0;
			for(int j=i;j>=1;--j){
				sum^=a[j];
				if(sum==m) dp[i]=max(dp[j-1]+1,dp[i]);
			}
			maxx=max(maxx,dp[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==1) {
		maxx=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) maxx++;
		}
		cout<<maxx;
		return 0;
	}
	for(int i=n;i>=1;i--)
		yh[i]=yh[i+1]^a[i],bj[yh[i]].push_back(i);
	for(int i=n;i>=1;i--){
		if(a[i]==m||yh[i]==m){
			if(a[i]==m)dp[i]=max(dp[i],dp[i+1]+1);
			else dp[i]=max(dp[i],1ll);
		}
		zs=yh[i]^m;
		for(auto j:bj[zs])
			if(j<i)dp[j]=max(dp[j],dp[i+1]+1);
		maxx=max(maxx,dp[i]);
//		cout<<dp[i]<<'\n';
	}
//	for(int i=n;i>=1;i--){
//		write(dp[i]);
//		putchar(' ');
//	}
	cout<<maxx;
	return 0;
}
/*
10 5
3
4
3
2
6
7
4
3
2
6
*/