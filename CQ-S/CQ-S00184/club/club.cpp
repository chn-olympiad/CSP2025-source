#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int maxn=1e5+10;
int T;
int n;
int a[maxn][4];

struct NODE{
	int d,id,to,o,now;
	bool operator <(const NODE& other)const{
		return d>other.d;
	}
};

pair<int,int> check(int i){
	int mx=max({a[i][1],a[i][2],a[i][3]});
	if(a[i][1]==mx) return{1,(a[i][2]>a[i][3]?2:3)};
	if(a[i][2]==mx) return{2,(a[i][1]>a[i][3]?1:3)};
	return {3,(a[i][1]>a[i][2]?1:2)};
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
		priority_queue<NODE> Q[4];
		for(int i=1;i<=n;i++){
			pair<int,int> s=check(i);
			int o;
			if(s.fi==1) o=(s.se==2?3:2);
			else if(s.fi==2) o=(s.se==1?3:1);
			else o=(s.se==1?2:1);
			Q[s.fi].push({a[i][s.fi]-a[i][s.se],i,s.se,o,s.fi});
		} 
		int s1,s2,s3,mx=max({Q[1].size(),Q[2].size(),Q[3].size()});
		if(Q[1].size()==mx){
			s1=1;
			if(Q[2].size()>Q[3].size()) s2=2,s3=3;
			else s2=3,s3=2;
		}
		else if(Q[2].size()==mx){
			s1=2;
			if(Q[1].size()>Q[3].size()) s2=1,s3=3;
			else s2=3,s3=1;
		}
		else{
			s1=3;
			if(Q[1].size()>Q[2].size()) s2=1,s3=2;
			else s2=2,s3=1;
		}
		while(Q[s1].size()>n/2){
			NODE s=Q[s1].top();Q[s1].pop();
			Q[s.to].push({a[s.id][s.to]-a[s.id][s.o],s.id,s.o,s.now,s.to});
			while(Q[s2].size()>n/2){
				s=Q[s2].top();Q[s2].pop();
				Q[s.to].push({a[s.id][s.to]-a[s.id][s.o],s.id,s.o,s.now,s.to});
			}
			while(Q[s3].size()>n/2){
				s=Q[s3].top();Q[s3].pop();
				Q[s.to].push({a[s.id][s.to]-a[s.id][s.o],s.id,s.o,s.now,s.to});
			}
		}
		ll ans=0;
		while(Q[1].size()) ans+=(ll)a[Q[1].top().id][Q[1].top().now],Q[1].pop();
		while(Q[2].size()) ans+=(ll)a[Q[2].top().id][Q[2].top().now],Q[2].pop();
		while(Q[3].size()) ans+=(ll)a[Q[3].top().id][Q[3].top().now],Q[3].pop();
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
3 
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/
