#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
const int N=2e5+5;
int n,a[N][3];
priority_queue<int> q[3];
void solve(){
	scanf("%d",&n);
	for(int x=0;x<3;x++)while(!q[x].empty())q[x].pop();
	int ans=0;
	for(int i=1,x,y,z;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		ans+=max(max(x,y),z);
		if(x>=max(y,z))q[0].push(max(y,z)-x);
		else if(y>=z)q[1].push(max(x,z)-y);
		else q[2].push(max(x,y)-z);
	}
	for(int x=0;x<3;x++)while(q[x].size()>n/2)ans+=q[x].top(),q[x].pop();
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}

