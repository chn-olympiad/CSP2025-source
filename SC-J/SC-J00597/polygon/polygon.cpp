#include<bits/stdc++.h>
using namespace std;
#define ak ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//don't use fclose
//不开ll___
//数组开小直接炸
#define sqrt sqrtl
#define int long long
const int maxn=5010;
int a[maxn],dp[maxn],n,cnt=0;
inline int randr(int l,int r){return rand()%(r-l+1)+l;}
#define randf(l,r) for(int i=l;i<=r;i=randr(l,r))
unordered_map<vector<bool>,bool> vis;
int dfs(vector<bool> S,int sum,int ma){
	if(vis[S])return 0;
	vis[S]=1;
	int b=0;
	for(int i=0;i<S.size();i++){
		if(S[i])b++;
	}
	bool pd=1;
	if((sum<=2*ma&&sum!=0)||b<3){pd=0;}
	if(pd)cnt++;
	int as=0;
	if(pd)as++;
	for(int j=1;j<=n;j++){
		if(S[j])continue;
		vector<bool> S2=S;
		S2[j]=1;
		as+=dfs(S2,sum+a[j],max(ma,a[j]));
	}
	return as;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0,ma=0;
	cin>>n;
	vis.clear();
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i],ma=max(ma,a[i]);
	vector<bool> Ss(n+1,0);
	if(ma==1){//只能构成正的多边形
		cout<<n-2;
		return 0;
	}
	else cout<<dfs(Ss,0,0);
	return 0;
}