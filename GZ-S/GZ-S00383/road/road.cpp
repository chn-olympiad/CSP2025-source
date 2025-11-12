// GZ-S00383 贵阳市第一中学 胡祺然 
#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,ans[10010][20],tot,fa[10010],c[20],c1[20][10010],mi[10010][20],ans1,z1,T,mi1,mi2;
struct node{
	int u,v,val;
}l[N];
bool cmp(node x,node y){
	return x.val<y.val;
} 
int find(int x){
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y,z;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		l[i].u=x;
		l[i].v=y;
		l[i].val=z;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(l+1,l+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>c1[i][j];
			ans[j][i]=c[i]+c1[i][j];
			mi[j][i]=c1[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		x=find(l[i].u);
		y=find(l[i].v);
		if(x==y)continue;
		if(x>y)swap(x,y); 
		fa[y]=x;
		mi1=ans[x][0];
		mi2=ans[y][0];
		ans[x][0]+=ans[y][0];
		ans[x][0]+=l[i].val;
		z=ans[x][0];
		z1=l[i].val;
		for(int j=1;j<=k;j++){
			if(z>ans[x][j]+ans[y][j]-c[j]){
				z=ans[x][j]+ans[y][j]-c[j];
			}
			z1=min(z1,mi[x][j]+mi[y][j]+c[j]);
			mi1=min(mi1,ans[x][j]);
			mi2=min(mi2,ans[y][j]);
		}
		for(int j=1;j<=k;j++){
			T=ans[x][j];
			ans[x][j]=min(z+min(mi[x][j],mi[y][j])+c[j],ans[x][j]+ans[y][j]-c[j]);
			ans[x][j]=min(ans[x][j],min(z1+T+mi2,z1+ans[y][j]+mi1));
		}
		for(int j=1;j<=k;j++){
			mi[x][j]=min(mi[x][j],mi[y][j]);
		}
	}
	ans1=ans[1][0];
	for(int i=1;i<=k;i++){
		ans1=min(ans1,ans[1][i]);
	}
	cout<<ans1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
