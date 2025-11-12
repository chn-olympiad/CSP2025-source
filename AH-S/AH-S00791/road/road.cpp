#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,kk,k,m;
long long ans;
struct node{
	int u,v,w;
}a[2000005];
int b[12][10005],c[13],fa[10005],l[10005];
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
int gf(int i){
		if(fa[i]==i)return i;
		return fa[i]=gf(fa[i]);
}
long long ks(int h){
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(a[i].u>n&&((h&(1<<(k-a[i].u+n)))==0))continue;
		//cout<<k-a[i].v+n<<"&"<<h;;
		if(a[i].v>n&&((h&(1<<(k-a[i].v+n)))==0))continue;
		int f1=gf(a[i].u),f2=gf(a[i].v);
	//	printf("%d %d   ",a[i].u,a[i].v);
		if(f1==f2)continue;
		fa[f1]=f2;
		ans+=a[i].w;
	}
	return ans;
}
void dfs(int e,int i,long long sum){
	if(i==k+1){
		for(int ii=1;ii<=n+k;ii++)fa[ii]=ii;
		ans=min(ans,sum+ks(e));
	//	printf("%d %d %d \n",ans,sum,e);
		return ;
	}
	if(sum>ans)return ;
	dfs(e*2+1,i+1,sum+b[i][0]);
	dfs(e*2,i+1,sum);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<(0&0);
	bool  hh=1;
	cin>>n>>m>>kk;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=kk;i++){
		scanf("%d",&c[i]);
		if(c[i]==1)hh=0;
		int p=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&l[j]);
			if(c[i]==0&&l[j]==0)p=j;
		}
		if(p==0){
			k++;
			b[k][0]=c[i];
			for(int j=1;j<=n;j++)
				b[k][j]=l[j];
		}
		else {
			for(int j=1;j<=n;j++)
				if(p!=j){
					a[++m].u=j;a[m].v=p;
					a[m].w=l[j];
				}
		}
	}
//	cout<<k;
	sort(a+1,a+m+1,cmp);	
	ans=ks(0);
	//cout<<ans<<" ";
	if(k==0)printf("%lld",ans);
	else{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				a[++m].u=j;
				a[m].v=i+n;
				a[m].w=b[i][j];
				//a[m].id=i;
		}
	//	for(int i=1;i<=m;i++)
		//	printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
		sort(a+1,a+m+1,cmp);		
		dfs(0,1,0);
		cout<<ans;
	}
//	cout<<"^^^"<<n;
	return 0;
}
