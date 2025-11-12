#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int len=0;
int fa[20005];
struct node{
	int u,v,w,id;
}a[1000005];
struct node1{
	int w,id;
};
bool cmp2(node1 q,node1 p){
	return q.w<p.w;
}
long long ans=0;
long long sum=0,othersum=0;
int cnt=0,s=0;
int cost[10005];
node1 cont[15][10005];
node haobian[200005];
int ss,pre,gai,newlen,use,uses;
int next[1000005];
int ssss=0;
bool cmp(node p,node q){
	return p.w<q.w;
}
int getfa(int x){
	return (x==fa[x]?x:fa[x]=getfa(fa[x]));
}
int merge(int x,int y){
	int fax=getfa(x),fay=getfa(y);
	if(fax==fay)return 0;
	fa[fax]=fay;
	return 1;
}
int getwei(int x){
	int sum=0;
	while(x){
		sum++;
		x>>=1;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&cost[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&cont[i][j].w);
			cont[i][j].id=j;
		}
		cont[i][0].w=-1;
		sort(cont[i]+1,cont[i]+n+1,cmp2);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(merge(a[i].u,a[i].v)){
			haobian[++len]=a[i];
			haobian[len].id=-1;
			ans+=a[i].w;
		}
	}
	for(int i=1;i<(1<<k);i++){
		ss=i ^ (i>>1);
		pre=(i-1) ^ ((i-1)>>1);
		gai=pre ^ ss;
		for(int j=1;j<=n;j++){
			fa[j]=j;
			fa[j+n]=j+n;
		}
		if(ss&gai){
			gai=getwei(gai);
			othersum+=cost[gai];
			use=n;
			len+=n;
			for(int j=len;j>=1;j--){
				if(cont[gai][use].w<haobian[j-use].w&&j-use>0){
					haobian[j]=haobian[j-use];
				}
				else{
					haobian[j]={gai+n,cont[gai][use].id,cont[gai][use].w,gai+n};
					use--;
				}
			}
			ssss++;
		}
		else{
			gai=getwei(gai);
			othersum-=cost[gai];
			use=0;
			for(int j=1;j<=len;j++){
				if(haobian[j].id==gai+n){
					use++;
				}
				else{
					haobian[j-use]=haobian[j];
				}
			}
			len-=n;
			ssss--;
		}
		sum=othersum;
		for(int j=1;j<=len;j++){
			if(merge(haobian[j].u,haobian[j].v)){
				sum+=haobian[j].w;
			}
		}
//		cout<<sum<<" ";
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
