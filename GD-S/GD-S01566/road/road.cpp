#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,N1=1e3+5;
int n,m,k,fa[N],w[11][N],w1[N1][N1],maxw;
long long ans=0;
struct node{
	int u,v,w;
}a[M+10*N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	int sum=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=a[i].w;
			sum++;
			if(sum==n-1){
				maxw=a[i].w;
				break;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	memset(w1,0x7f,sizeof(w1));
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
		w1[a[i].u][a[i].v]=w1[a[i].v][a[i].u]=a[i].w;
	}
	for(int i=1;i<=k;i++){
		w[i][0]=read();
		for(int j=1;j<=n;j++) w[i][j]=read(); 
	}
	kruskal();
	//cout<<ans<<endl;
	if(k==0){
		cout<<ans;
		return 0;
	}
	long long d=0,ans1=ans,ans2=ans;
	int m1=m;
	ans=0;
	for(int i=1;i<=k;i++){
		if(ans1<=w[i][0]) continue;
		d=-w[i][0];
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				int x=w[i][l]+w[i][r];
				if(x>w1[l][r]||x>maxw) continue;
				d=d+(w1[l][r]-x);
				a[++m]={l,r,x};
				w1[l][r]=x;
			}
		}
		if(d>0){
			ans+=w[i][0];
		}
		else m=m1;
		m1=m;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	kruskal();
	cout<<min(ans,ans2);
	fclose(stdin);fclose(stdout);
}
