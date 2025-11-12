#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	using Vi=vector<int>;
	using node=pair<int,int>;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int n;t-- and cin>>n;){
		vector<Vi>a(n+1,Vi(3));
		Vi Mx(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] and a[i][0]>=a[i][2])Mx[i]=0;
			else if(a[i][1]>=a[i][2])Mx[i]=1;
			else Mx[i]=2;
		}
		priority_queue<node>Q[3];
		auto F=[&](int x,int now){//第x个人在第now个位置要跳槽 
			int res=0,G=-1e8;
			for(int u=0;u<=2;u++)
				if(u!=now and a[x][u]-a[x][now]>G)
					G=a[x][u]-a[x][now],res=u;
			node ret={G,res};
			return ret;
		};
		int ans=0;
		for(int i=1;i<=n;i++){
			node ret=F(i,Mx[i]);
			Q[Mx[i]].push({ret.first,i});
			ans+=a[i][Mx[i]];
			if(Q[Mx[i]].size()>n/2){//要跳槽 
				node now=Q[Mx[i]].top();
				Q[Mx[i]].pop();
				int u=now.second;
				ret=F(u,Mx[i]);//跳去哪里？ 
				ans+=ret.first;
				now=F(u,ret.second);//还要跳怎么办？ 
				Q[ret.second].push({now.first,u}); 
			} 
		}
		cout<<ans<<endl;
		/*
		发现如果冲突，则仅可能冲突一个部门。
		发现DP存在后效性，必须贪心。 
		*/ 
	}
	return 0;
} 
