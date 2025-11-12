#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a[4];
	//long long mx;
} d[100100];
int n;
long long cnt[4],ans=0;
void dfs(int x,long long g){
	//cout<<x<<" "<<g<<"	"<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<endl;
	if(x==n+1){
		ans=max(ans,g);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]==n/2) continue;
		cnt[i]++;
		dfs(x+1,g+d[x].a[i]);
		cnt[i]--;
	}
}
bool cmp(node xx,node yy){
	return xx.a[1]>yy.a[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int flag=1;
		cnt[1]=0; cnt[2]=0; cnt[3]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i].a[1],&d[i].a[2],&d[i].a[3]); 
			if(d[i].a[2]!=0 || d[i].a[3]!=0) flag=0;
			//sort(d[i].a+1,d[i].a+3);
			//d[i].mx=d[i].a[1];
		}
		if(flag==1){
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=d[i].a[1];
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
} 
