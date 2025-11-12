#include<bits/stdc++.h>
#define N 100010
using namespace std;
int T,n,a[N][3],ans;
struct ed{
	int k,a1,b1,c1,cnt;
};
queue<ed> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		q.push({0,0,0,0,0});
		while(!q.empty()){
			ed u=q.front();
			u.k++;
			q.pop();
			if(u.k>n){
				if(ans<u.cnt) ans=u.cnt;
				continue;
			}
			if(u.a1<n/2) q.push({u.k,u.a1+1,u.b1,u.c1,u.cnt+a[u.k][0]});
			if(u.b1<n/2) q.push({u.k,u.a1,u.b1+1,u.c1,u.cnt+a[u.k][1]});
			if(u.c1<n/2) q.push({u.k,u.a1,u.b1,u.c1+1,u.cnt+a[u.k][2]});
		}
		printf("%d\n",ans);
	}
	return 0;
}
