#include<bits/stdc++.h>
using namespace std;
#define ll long long
int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,k,a[15][10005],c[15],w[15],f[10005],flag;
struct node{int x,y,val;}s[8000005],p[8000005];
ll ans=1e15;
bool cmp(node a,node b){return a.val<b.val;}
int find(int x){
	if (x==f[x])return x;
	return f[x]=find(f[x]);
}
bool work(int x,int y){
	x=find(x);y=find(y);
	if (x==y)return 0;
	f[y]=x;return 1;
}
void dfs(int x,int cnt,ll val){
	if (val>ans)return ;
	if (x>k){
		for (int i=1;i<=n;i++)f[i]=i;
		for (int i=1;i<=m;i++)p[i]=s[i];
		int tot=m,sum=0;
		ll q=0;
		for (int i=1;i<=cnt;i++)
			for (int j=1;j<=n;j++)
				for (int o=j+1;o<=n;o++)
					p[++tot]={j,o,a[w[i]][j]+a[w[i]][o]};
		sort(p+1,p+1+tot,cmp);
		for (int i=1;i<=tot&&sum<n;i++){
			if (work(p[i].x,p[i].y)){
				sum++;
				q+=p[i].val;
			}
		}
		ans=min(ans,q+val);
		return ;
	}
	w[cnt+1]=x;
	dfs(x+1,cnt+1,val+c[x]);
	dfs(x+1,cnt,val);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for (int i=1;i<=m;i++){
		int x=in(),y=in(),z=in();
		s[i]={x,y,z};
	}
	for (int i=1;i<=k;i++){c[i]=in();if (c[i])flag=1;for (int j=1;j<=n;j++)a[i][j]=in();}
	if (flag)
		dfs(1,0,0);
	else {
		for (int i=1;i<=n;i++)f[i]=i;
		for (int i=1;i<=m;i++)p[i]=s[i];
		int tot=m,sum=0;
		ll q=0;
		for (int i=1;i<=k;i++)
			for (int j=1;j<=n;j++)
				for (int o=j+1;o<=n;o++)
					p[++tot]={j,o,a[i][j]+a[i][o]};
		sort(p+1,p+1+tot,cmp);
		for (int i=1;i<=tot&&sum<n;i++){
			if (work(p[i].x,p[i].y)){
				sum++;
				q+=p[i].val;
			}
		}
		ans=min(ans,q);
	}
	printf ("%lld",ans);
	return 0;
}
