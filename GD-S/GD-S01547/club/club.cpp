#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long LL;
typedef pair<int,int> PII;
struct Node{
	int x,id;
}a[N][4];
int pos[N];
priority_queue<PII,vector<PII>,greater<PII> > q[4];
bool cmp(Node x,Node y){
	return x.x>y.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].x,&a[i][2].x,&a[i][3].x);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp);
			pos[i]=1;
			q[a[i][1].id].push({a[i][1].x-a[i][2].x,i});
		}
		while(q[1].size()>n/2||q[2].size()>n/2||q[3].size()>n/2){
			int x=0;
			if(q[1].size()>n/2)x=1;
			if(q[2].size()>n/2)x=2;
			if(q[3].size()>n/2)x=3;
			PII f=q[x].top();
			q[x].pop();
			if(pos[f.second]==2)q[a[f.second][++pos[f.second]].id].push({1e9,f.second});
			else {
				q[a[f.second][pos[f.second]+1].id].push({a[f.second][pos[f.second]+1].x-a[f.second][pos[f.second]+2].x,f.second});
				pos[f.second]++;
			}
		}
		LL res=0;
		while(q[1].size()){
			PII f=q[1].top();
			q[1].pop();
			res+=a[f.second][pos[f.second]].x;
		}
		while(q[2].size()){
			PII f=q[2].top();
			q[2].pop();
			res+=a[f.second][pos[f.second]].x;
		}
		while(q[3].size()){
			PII f=q[3].top();
			q[3].pop();
			res+=a[f.second][pos[f.second]].x;
		}
		printf("%lld\n",res);
	} 
	return 0;
}
