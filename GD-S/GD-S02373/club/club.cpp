#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,cntfen[5],cntstu[5];

struct stu{
	int f[5];
	int first,second,y;
}a[100005];

void st(stu &x){
	if(x.f[1]>=x.f[2]&&x.f[1]>=x.f[3]){
		x.first=1;
		if(x.f[2]>=x.f[3]){
			x.second=2;
		}else{
			x.second=3;
		}
	}else if(x.f[2]>=x.f[1]&&x.f[2]>=x.f[3]){
		x.first=2;
		if(x.f[1]>=x.f[3]){
			x.second=1;
		}else{
			x.second=3;
		}
	}else if(x.f[3]>=x.f[1]&&x.f[3]>=x.f[2]){
		x.first=3;
		if(x.f[1]>=x.f[2]){
			x.second=1;
		}else{
			x.second=2;
		}
	}
	x.y=x.f[x.first]-x.f[x.second];
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q[5];
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%lld",&a[i].f[j]);
			st(a[i]);
			q[a[i].first].push(make_pair(a[i].y,i));
		}
		int ccnt=0;
		for(int i=1;i<=3;i++){
			if(q[i].size()<=n/2){
				while(!q[i].empty()){
					ccnt+=a[q[i].top().second].f[a[q[i].top().second].first];
					q[i].pop();
				}
			}else{
				while(q[i].size()>n/2){
					ccnt+=a[q[i].top().second].f[a[q[i].top().second].second];
					q[i].pop();
				}
				while(!q[i].empty()){
					ccnt+=a[q[i].top().second].f[a[q[i].top().second].first];
					q[i].pop();
				}
			}
		}
		printf("%lld\n",ccnt);
	}
	
	return 0;
}
