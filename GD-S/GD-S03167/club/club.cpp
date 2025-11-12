#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,ans;
int a[N][5],cnt[5];
priority_queue<pair<int,int> >q[4];

void init(){
	cnt[1]=cnt[2]=cnt[3]=ans=0;
	for(int i=1;i<=3;i++) for(;!q[i].empty();) q[i].pop();
}

int add(int whx,int id){
	int w=a[whx][id];
	if(cnt[id]<(n>>1)) return w;
	int cha=-q[id].top().first,why=q[id].top().second,maxn=-1e9;
	for(int i=1;i<=3;i++){
		if(i==id) continue;
		maxn=max(maxn,a[why][i]-cha+w);
	}
	return maxn;
}

void change(int whx,int id){
	int w=a[whx][id];
	if(cnt[id]<(n>>1)){
		q[id].push({-w,whx});
		cnt[id]++;
		ans+=w;
		return;
	}
	int cha=-q[id].top().first,why=q[id].top().second,maxn=-1e9,maxv=0;
	q[id].pop(); 
	for(int i=1;i<=3;i++){
		if(i==id) continue;
		int val=add(why,i);
		if(maxn<val){
			maxn=val;
			maxv=i;
		}
	}
	ans+=w+maxn-cha;
	q[maxv].push({-a[why][maxv],why});
	cnt[maxv]++;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t--;){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++){
			int maxn=-1e9,maxv=1;
			for(int j=1;j<=3;j++){
				if(maxn<add(i,j)){
					maxn=add(i,j);
					maxv=j;
				}
			}
			change(i,maxv);
		}
		printf("%d\n",ans);
	}
}
