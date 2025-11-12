#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int T,n,tot,gs[3],del[N],a[N][3];
struct node{
	int val,id,op,w;
	friend bool operator <(const node a,const node b){
		return a.val<b.val;
	}
};
priority_queue<node>q[3];
void add(int i,int o){
	tot++;
	for(int j=0;j<3;j++)
	  if(j!=o) q[o].push({a[i][j]-a[i][o],tot,j,i});
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,tot=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		memset(del,0,sizeof(del));
		long long s=0;
		gs[0]=gs[1]=gs[2]=0;
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		for(int i=1;i<=n;i++){
			int mx=max(a[i][0],max(a[i][1],a[i][2]));
			s+=mx;
			if(mx==a[i][0]) add(i,0),gs[0]++;
			else if(mx==a[i][1]) add(i,1),gs[1]++;
			else if(mx==a[i][2]) add(i,2),gs[2]++;
			for(int j=0;j<3;j++){
				if(gs[j]<=n/2) continue;
				while(!q[j].empty()){
					node t=q[j].top();q[j].pop();
					if(del[t.id]) continue;
					del[t.id]=1,s+=t.val;
					gs[j]--,gs[t.op]++;
					add(t.w,t.op);
					break;
				}
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
