#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,dp[N],sa,sb,sc,ma,mb,mc,ans;
struct node{
	int a,b,c;
}a[N];
bool cmp1(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.b>b.b;
}
bool cmp3(node a,node b){
	return a.c>b.c;
}
void dfs(int s,int la,int lb,int lc,int d){
	if(d>n){
		ans=max(ans,s);
		return;
	}
	if(la<n/2)
		dfs(s+a[d].a,la+1,lb,lc,d+1);
	if(lb<n/2)
		dfs(s+a[d].b,la,lb+1,lc,d+1);
	if(lc<n/2)
		dfs(s+a[d].c,la,lb,lc+1,d+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		sa=0,sb=0,sc=0,ma=0,mb=0,mc=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c)
				sa++;
			if(a[i].b>=a[i].a&&a[i].b>a[i].c)
				sb++;
			if(a[i].c>=a[i].a&&a[i].c>=a[i].b)
				sc++;
			ma=max(a[i].a,ma),mb=max(a[i].b,mb),mc=max(a[i].c,mc);
		}
		if(mb==0&&mc==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].a;
			cout<<ans<<"\n";
			continue;
		}
		if(ma==0&&mc==0){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].b;
			cout<<ans<<"\n";
			continue;
		}
		if(ma==0&&mb==0){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].c;
			cout<<ans<<"\n";
			continue;
		}
		if(sa<=n/2&&sb<=n/2&&sc<=n/2){
			for(int i=1;i<=n;i++)
				ans+=max({a[i].a,a[i].b,a[i].c});
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}
