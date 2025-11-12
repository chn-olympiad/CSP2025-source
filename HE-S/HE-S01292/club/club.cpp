#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m,T,ans,num[3];
struct node{
	int x,y;
	bool operator < (node k)const{
		return x<k.x;
	}
}p[N][3];
bool cmp(node fir,node sec){
	return fir.x>sec.x;
}
priority_queue<node>q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(num,0,sizeof(num));
		while(!q.empty())q.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i][0].x,&p[i][1].x,&p[i][2].x);
			for(int j=0;j<3;j++)p[i][j].y=j;
			sort(p[i],p[i]+3,cmp);
			if(num[p[i][0].y]==n/2){
				while(!q.empty()){
					if(q.top().y==p[i][0].y)break;
					q.pop();
				}
				node u=q.top();
				if(p[i][1].x>=u.x+p[i][0].x){
					ans+=p[i][1].x;
				}
				else {
					q.pop();
					ans+=u.x+p[i][0].x;
					q.push({p[i][1].x-p[i][0].x,p[i][0].y});
				}
			}
			else {
				num[p[i][0].y]++;
				ans+=p[i][0].x;
				q.push({p[i][1].x-p[i][0].x,p[i][0].y});
			}
		}
		printf("%d\n",ans);
	}
}