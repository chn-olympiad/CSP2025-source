#include<bits/stdc++.h>
using namespace std;
long long ans=1e16;
int st[1010005],ed[1010005];
long long cost[1010005];
int st1[1010005],ed1[1010005];
long long cost1[1010005];
int id[1010005];
int cmp1(int x,int y){
	return cost1[x]<cost1[y];
}
long long c[20],d[20][10005],ch[20];
int fa[10005];
int find(int a){
	if(fa[a]==a)
		return a;
	fa[a]=find(fa[a]);
	return fa[a];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&st[i],&ed[i],&cost[i]);
	}
	//cout<<"1"<<endl;
	int test=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0){
			ch[i]=1;
		}
		for(int j=1;j<=n;j++){
			scanf("%lld",&d[i][j]);
			if((ch[i]==1)&&(d[i][j]==0)){
				ch[i]=2;				
			}
		}
	    if(ch[i]!=2){
	    	test=0;
		}
	}
	//cout<<"1"<<endl;
	for(int cc=0;cc<(1<<k);cc++){
		if(test){
			cc=(1<<k)-1;
		}
		int t=1;
		for(int i=1;i<=k;i++){
			if(ch[i]==2&&(((cc>>(i-1))&1)==0)){
				t=0;
				break;				
			}
		}
		if(t==0){
			continue;
		} 
		//cout<<cc<<endl;
		for(int i=1;i<=m;i++){
			st1[i]=st[i];
			ed1[i]=ed[i];
			cost1[i]=cost[i];
			id[i]=i;
		}
		int top=m+1;
		long long sum=0;
		int cnt=1;
		for(int i=1;i<=k;i++){
			if(cc&(1<<(i-1))){
				sum+=c[i];
				cnt--;
				for(int j=1;j<=n;j++){
					ed1[top]=n+i;
					st1[top]=j;
					cost1[top]=d[i][j];
					id[top]=top;
					top++;
				}
			}
		}
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		sort(id+1,id+top,cmp1);
		int x=0;
		while(cnt<n){
			x++;
			if(x>=top){
				printf("error");
			}
			if(find(st1[id[x]])!=find(ed1[id[x]])){
				fa[fa[st1[id[x]]]]=fa[ed1[id[x]]];
				cnt++;
				sum+=cost1[id[x]];
			}
		}
		if(ans>sum){
			ans=sum;
		}
	}
	printf("%lld",ans);
	return 0;
}