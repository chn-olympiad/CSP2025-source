#include<bits/stdc++.h>
using namespace std;
long long s[100001][4];
long long vis[100001];
int r[100001],sum[4];
struct bmy{
	int id;
	long long v;
}Del[200001];
int dsum;
bool cmp(bmy a,bmy b){return a.v<b.v;}
void work(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&s[i][1],&s[i][2],&s[i][3]);
	long long now=0;
	for(int i=1;i<=n;i++){
		if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3])r[i]=1,now+=s[i][1],s[i][0]=s[i][1];
		else if(s[i][2]>=s[i][3])r[i]=2,now+=s[i][2],s[i][0]=s[i][2];
		else r[i]=3,now+=s[i][3],s[i][0]=s[i][3];
	}
	sum[1]=sum[2]=sum[3]=0;
	for(int i=1;i<=n;i++)sum[r[i]]++;
	if(sum[1]*2<=n&&sum[2]*2<=n&&sum[3]*2<=n){
		printf("%lld\n",now);
		return;
	}
	dsum=0;
	int cs;
	if(sum[1]*2>n)cs=1;
	else if(sum[2]*2>n)cs=2;
	else cs=3;
	for(int i=1;i<=n;i++){
		if(r[i]!=cs)continue;
		for(int j=1;j<=3;j++){
			if(j!=cs){
				dsum++;
				Del[dsum].id=i;
				Del[dsum].v=s[i][0]-s[i][j];
			}
		}
	}
	sort(Del+1,Del+dsum+1,cmp);
	memset(vis,0,sizeof(vis));
	int nowsum=0;
	for(int i=1;i<=dsum;i++){
		if(!vis[Del[i].id]){
			now-=Del[i].v;
			vis[Del[i].id]=1;
			nowsum++;
		}
		if(nowsum>=sum[cs]-n/2)break;
	}
	printf("%lld\n",now);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)work();
	return 0;
}
