#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int t,n,flag1,flag,f,ans,mx;
struct p{
	int a,b,c;
};
p r[N];
int vis[5],dp[1005][1005];
void dfs(int ai,int bi,int ci,int sum,int i){
	if(ai>mx||bi>mx||ci>mx) return;
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	dfs(ai+1,bi,ci,sum+r[i].a,i+1);
	dfs(ai,bi+1,ci,sum+r[i].b,i+1);
	dfs(ai,bi,ci+1,sum+r[i].c,i+1);
}
bool cmp(p x,p y){
	if(x.a!=y.a) return x.a>y.a;
//	if(x.b!=y.b) return x.b>y.b;
//	if(x.c!=y.c) return x.c>y.c;
}
bool cmp1(p x,p y){
//	if(x.a!=y.a) return x.a>y.a;
	if(x.b!=y.b) return x.b>y.b;
//	if(x.c!=y.c) return x.c>y.c;
}
bool cmp2(p x,p y){
//	if(x.a!=y.a) return x.a>y.a;
//	if(x.b!=y.b) return x.b>y.b;
	if(x.c!=y.c) return x.c>y.c;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		flag1=0;
		flag=0;
		f=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
			if(r[i].b!=0||r[i].c!=0) flag1++;
			if(r[i].a!=0||r[i].b!=0) flag++;
			if(r[i].a!=0||r[i].c!=0) f++;
		}
		if(n==2){
			cout<<max(r[1].a+r[2].b,max(r[1].b+r[2].a,max(r[1].a+r[2].c,max(r[1].b+r[2].c,max(r[1].c+r[2].a,r[1].c+r[2].b)))));
			continue;
		}
		mx=n/2;
		if(flag1==0){
			sort(r+1,r+n+1,cmp);
			for(int i=1;i<=mx;i++) ans+=r[i].a;
			cout<<ans<<"\n";
			continue;
		}
		if(flag==0){
			sort(r+1,r+n+1,cmp2);
			for(int i=1;i<=mx;i++) ans+=r[i].c;
			cout<<ans<<"\n";
			continue;
		}
		if(f==0){
			sort(r+1,r+n+1,cmp1);
			for(int i=1;i<=mx;i++) ans+=r[i].b;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=max(r[i].a,max(r[i].b,r[i].c));
			if(r[i].a>r[i].b&&r[i].a>r[i].c) vis[1]++;
			else if(r[i].b>r[i].a&&r[i].b>r[i].c) vis[2]++;
			else if(r[i].c>r[i].a&&r[i].c>r[i].b)vis[3]++;
			else vis[4]++;
		}
		if(vis[1]<=mx&&vis[2]<=mx&&vis[3]<=mx){
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
} 