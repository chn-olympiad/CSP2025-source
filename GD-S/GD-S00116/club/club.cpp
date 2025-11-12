#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
int n,a[N][4],b[N],p[N],ans=-LLONG_MAX;
int cnt[4];
void dfs1(int u){
	if(u==n+1){
		int cur=0;
		for(int i=1;i<=n;++i){
			cur+=a[i][p[i]];
		}
		ans=max(ans,cur);
		return;
	}
	for(int i=1;i<=3;++i){
		if(cnt[i]+1<=n/2){
			p[u]=i;
			++cnt[i];
			dfs1(u+1);
			--cnt[i];
		}
	}
}
void Solve1(){
	dfs1(1);
	cout<<ans<<'\n';
}
void Solve2(){
	
}
void Solve3(){
	for(int i=1;i<=n;++i){
		b[i]=a[i][1];
	}
	sort(b+1,b+1+n);
	int res=0;
	for(int i=n;i>n/2;--i){
		res+=b[i];
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		ans=-LLONG_MAX;
		cin>>n;
		bool special_B=1,special_A=1;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]) special_B=0,special_A=0;
			if(a[i][2]) special_A=0;
		}
		if(n<=30){
			Solve1();	
		}else if(special_A){
			Solve3();
		}else if(special_B){
			Solve2();
		}
	}
	return 0;
}
