#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct sb{
	int d[4]={0},m[4]={0};
}a[100010];
int t,n,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > >q[4];
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].m[1],&a[i].m[2],&a[i].m[3]);
			a[i].d[1]=1; a[i].d[2]=2; a[i].d[3]=3;
			for(int j=1;j<=3;j++){
				for(int k=1;k<=2;k++){
					if(a[i].m[k]<a[i].m[k+1]){
						swap(a[i].m[k],a[i].m[k+1]);
						swap(a[i].d[k],a[i].d[k+1]);
					}
				}
			}
			/*for(int j=1;j<=3;j++){
				printf("%d %d\n",a[i].d[j],a[i].m[j]);
			}*/
			if(q[a[i].d[1]].size()==n/2){
				int sbb=q[a[i].d[1]].top().second;
				if(ans-a[sbb].m[1]+a[i].m[1]+a[sbb].m[2]>ans+a[i].m[2]){
					ans=ans-a[sbb].m[1]+a[i].m[1]+a[sbb].m[2];
					q[a[sbb].d[2]].push(make_pair(a[sbb].m[2],sbb));
					q[a[i].d[1]].pop();
					q[a[i].d[1]].push(make_pair(a[i].m[1],i));
				}else{
					q[a[i].d[2]].push(make_pair(a[i].m[2],i));
					ans=ans+a[i].m[2];
				}
			}else{
				q[a[i].d[1]].push(make_pair(a[i].m[1],i));
				ans=ans+a[i].m[1];
			}
			//printf("%d %d\n",q[a[i].d[1]].top().first,q[a[i].d[1]].top().second);
		}
		printf("%d\n",ans);
	}                                      
	return 0;
}