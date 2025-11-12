#include<bits/stdc++.h>
using namespace std;
int n,a[100010][4],rnk[100010][4],cnt[4],ans;
priority_queue<int> h;
void clear(){
	for(int i=1;i<=3;i++)
		cnt[i]=0;
	ans=0;
	while(!h.empty())
		h.pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			pair<int,int> ta[4];
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				ta[j]={a[i][j],j};
			}
			sort(ta+1,ta+3+1);
			for(int j=3;j>=1;j--)
				rnk[i][3-j+1]=ta[j].second;
			cnt[rnk[i][1]]+=1;
			ans+=a[i][rnk[i][1]];
		}
		int ti=0;
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>(n>>1))
			{
				ti=i;
				break;
			}
		}
		if(ti==0)
		{
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(rnk[i][1]!=ti)continue;
			h.push(a[i][rnk[i][2]]-a[i][rnk[i][1]]);
		}
		for(int i=1;i<=cnt[ti]-(n>>1);i++)
		{
			ans+=h.top();
			h.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
