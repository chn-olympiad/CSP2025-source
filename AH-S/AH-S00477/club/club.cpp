#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
int t,n;
int num[N][4],sam[N];
struct node{
	int cnt,id;
}cha[N];
bool cmp(node a,node b){
	return a.cnt<b.cnt;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	int ans,c[4],flag;
	while(t--){
		scanf("%lld",&n);
		memset(sam,0,sizeof(sam));
		memset(c,0,sizeof(c));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				scanf("%lld",&num[i][j]);
				if(num[i][j]>num[i][sam[i]]){
					sam[i]=j;
				}
			}
			cha[i].cnt=abs(num[i][sam[i]]-max(num[i][(sam[i]+1)%3],num[i][(sam[i]+2)%3]));
			cha[i].id=i;
			c[sam[i]]++;
			ans+=num[i][sam[i]];
		}
		flag=-1;
		sort(cha+1,cha+n+1,cmp);
		for(int i=0;i<=2;i++){
			if(c[i]>n/2){
				flag=i;
				break;
			}
		}
		if(flag!=-1){
			for(int i=1;i<=n;i++){
				if(sam[cha[i].id]==flag){
					c[flag]--,ans-=cha[i].cnt;
					if(c[flag]<=n/2){
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
