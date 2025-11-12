#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls k<<1
#define rs k<<1|1
#define maxn 505
const int P=998244353;
int n,m,a[maxn],p[maxn],jc[maxn],mx,ans,vis[maxn],sm[maxn];
void dfs(int j,int tg,int dd){
	if(dd>n-m)return;
	if(j==n+1){
		if(tg>=m)ans++;
		ans%=P;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(a[j]==1){
			vis[i]=1;
			if(dd>=p[i])dfs(j+1,tg,dd+1);
			else dfs(j+1,tg+1,dd);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			dfs(j+1,tg,dd+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    jc[1]=1;
    int sum=0;
    for(int i=1;i<=n;i++){
	    jc[i]=jc[i-1]*i%P;
	}
    for(int i=0;i<s.length();i++){
    	if(s[i]=='0')a[i+1]=0;
    	else a[i+1]=1;
    	sm[i+1]=(a[i+1]+1)%2+sm[i];
    	sum+=a[i+1];
		mx=max(a[i+1],mx);
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	sort(p+1,p+n+1);
	if(mx==0){
		cout<<jc[n];
		return 0;
	}
	if(m==n||m>sum){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
