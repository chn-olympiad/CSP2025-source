#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int a[N][4];
int tot[4];
int bl[N];
priority_queue<pair<int ,pair<int,int > > > q;
void work(){
	int n;
	scanf("%d",&n);
	long long sum=0;
	tot[1]=tot[2]=tot[3]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if(maxn==a[i][1])tot[1]++,sum+=a[i][1],bl[i]=1;
		else if(maxn==a[i][2])tot[2]++,sum+=a[i][2],bl[i]=2;
		else tot[3]++,sum+=a[i][3],bl[i]=3;
	}
	if(tot[1]<=n/2&&tot[2]<=n/2&&tot[3]<=n/2){
		printf("%lld\n",sum);
		return ;
	}
	while(!q.empty())q.pop();
	int now=0;
	for(int i=1;i<=3;i++)
		if(tot[i]>n/2)now=i;
	for(int i=1;i<=n;i++){
		if(bl[i]==now){
			for(int j=1;j<=3;j++){
				if(j==now)continue;
				q.push({a[i][j]-a[i][now],{i,j}});
			}
		}
	}
	while(tot[now]>n/2){
		int num=q.top().first,x=q.top().second.first,to=q.top().second.second;
		q.pop();
		if(bl[x]!=now||tot[to]==n/2)continue;
		sum+=num;
		bl[x]=to;
		tot[now]--,tot[to]++;
	} 
	printf("%lld\n",sum);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
