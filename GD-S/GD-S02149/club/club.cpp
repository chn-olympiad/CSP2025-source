#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>> 
using namespace std;
int T,n,v1[100010],v2[100010],ans=0;
struct str{
	int x,y,z;
}a[100010];
priority_queue<pii,vector<pii>,less<pii> > q ;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			pii t1,t2,t3;
			t1.first=a[i].x;
			t1.second.first=1;
			t1.second.second=i;
			t2.first=a[i].y;
			t2.second.first=2;
			t2.second.second=i;
			t3.first=a[i].z;
			t3.second.first=3;
			t3.second.second=i;
			q.push(t1);
			q.push(t2);
			q.push(t3);
		}
		while(!q.empty()){
			pii t=q.top();
			if(v1[t.second.first]<n/2&&v2[t.second.second]==0){
				v1[t.second.first]++;
				ans+=t.first;
				v2[t.second.second]=1;
			}
			q.pop();
		}
		printf("%d\n",ans);
	}
	
} 
