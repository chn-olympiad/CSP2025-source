#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;

struct Node{
	int a,b,c,v;
}d[N];
bool cmp(Node a,Node b){
	return a.v>=b.v;
}

int cnt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(d,0,sizeof(d));
		memset(cnt,0,sizeof(cnt));
		int n;
		scanf("%d",&n);
		int en=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&d[i].a,&d[i].b,&d[i].c);
			d[i].v=max(d[i].a,max(d[i].b,d[i].c));
		}
		sort(d+1,d+1+n,cmp);
		
		int ans=0;
		for(int i=2;i<=n;i++){
			if(d[i].a==d[i].v&&cnt[1]<en){
				cnt[1]++;
				ans+=d[i].v;
			}
			else if(d[i].b==d[i].v&&cnt[2]<en){
				cnt[2]++;
				ans+=d[i].v;
			}
			else if(d[i].c==d[i].v&&cnt[3]<en){
				cnt[3]++;
				ans+=d[i].v;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
