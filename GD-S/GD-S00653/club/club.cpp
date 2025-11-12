#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int INF=2147483647;
int T,n;
long long sum;
int d[MAXN];
int a[MAXN][4];
struct Edge1{
	int y,z;
	friend bool operator< (Edge1 p_,Edge1 q_){
		return max(p_.y,p_.z)<max(q_.y,q_.z);
	}
};
struct Edge2{
	int x,z;
	friend bool operator< (Edge2 p_,Edge2 q_){
		return max(p_.z,p_.x)<max(q_.z,q_.x);
	}
};
struct Edge3{
	int x,y;
	friend bool operator< (Edge3 p_,Edge3 q_){
		return max(p_.y,p_.x)<max(q_.y,q_.x);
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		priority_queue<Edge1>q1;
		priority_queue<Edge2>q2;
		priority_queue<Edge3>q3;
		scanf("%d",&n);
		d[1]=d[2]=d[3]=0,sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int u=max(a[i][1],max(a[i][2],a[i][3]));
			a[i][1]-=u,a[i][2]-=u,a[i][3]-=u;
			sum+=u;
		}
		for(int i=1;i<=n;i++){
			int u,p,q,M,N;
			if(a[i][1]==0) u=1,p=2,q=3;
			if(a[i][2]==0) u=2,p=1,q=3;
			if(a[i][3]==0) u=3,p=1,q=2;
			if(d[u]==n/2){
				if(u==1) M=q1.top().y,N=q1.top().z;
				if(u==2) M=q2.top().x,N=q2.top().z;
				if(u==3) M=q3.top().x,N=q3.top().y;
				sum+=max(a[i][p],max(a[i][q],max(N,M)));
				if(max(a[i][p],a[i][q])<max(N,M)){
					if(u==1) q1.pop(),q1.push((Edge1){a[i][2],a[i][3]});
					if(u==2) q2.pop(),q2.push((Edge2){a[i][1],a[i][3]});
					if(u==3) q3.pop(),q3.push((Edge3){a[i][1],a[i][2]});
				}
			}
			else{
				d[u]++;
				if(u==1) q1.push((Edge1){a[i][2],a[i][3]});
				if(u==2) q2.push((Edge2){a[i][1],a[i][3]});
				if(u==3) q3.push((Edge3){a[i][1],a[i][2]});
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522

1
4
0 1 0
0 1 0
0 2 0
0 2 0

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
