#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
int a[100005][4],a1[100005],b1[100005],c1[100005],ans;
priority_queue<pair<int,int> >q[4];
inline void Insert(int i){
	pair<int,int>aa[4];
	if(!q[1].empty())aa[1]=q[1].top();	if(!q[2].empty())aa[2]=q[2].top();	if(!q[3].empty())aa[3]=q[3].top();
	if(q[a1[i]].size()<(n+1)/2)q[a1[i]].push({1e9-a[i][a1[i]]+a[i][b1[i]],i});
	else if(1e9-aa[a1[i]].first<a[i][a1[i]]-a[i][b1[i]]){
		q[a1[i]].pop();q[a1[i]].push({1e9-a[i][a1[i]]+a[i][b1[i]],i}); 
		Insert(aa[a1[i]].second);
	}
	else if(q[b1[i]].size()<(n+1)/2)q[b1[i]].push({1e9-a[i][b1[i]]+a[i][c1[i]],i});
	else if(1e9-aa[b1[i]].first<a[i][b1[i]]-a[i][c1[i]]){
		q[b1[i]].pop();q[b1[i]].push({1e9-a[i][b1[i]]+a[i][c1[i]],i});
		Insert(aa[b1[i]].second);
	}
	else q[c1[i]].push({0,i});
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])a1[i]=1,b1[i]=2,c1[i]=3;
			else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])a1[i]=1,b1[i]=3,c1[i]=2;
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])a1[i]=2,b1[i]=1,c1[i]=3;
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])a1[i]=2,b1[i]=3,c1[i]=1;
			else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])a1[i]=3,b1[i]=1,c1[i]=2;
			else a1[i]=3,b1[i]=2,c1[i]=1;
			Insert(i);
		}
		for(int i=1;i<=3;i++)
			while(!q[i].empty()){
				pair<int,int>p=q[i].top();q[i].pop();
				ans+=a[p.second][i];
			}
		printf("%lld\n",ans);
	}
	return 0;
}
