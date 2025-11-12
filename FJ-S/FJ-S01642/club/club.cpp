//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//const ll N=1e5+5;
//
//struct node{ll x,id;}a[N][3];
//ll t,n,b[N],c[N][3],f[N][3],g[N][3][3],ans;
//
//ll read(){
//	ll x=0,f=1;char ch=getchar();
//	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
//	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
//	return x*f;
//}
//
//bool cmp1(node x,node y){return x.x>y.x;}
//
//bool cmp2(ll x,ll y){
//	if(a[x][0].x!=a[y][0].x)return a[x][0].x>a[y][0].x;
//	else if(a[x][1].x!=a[y][1].x)return a[x][1].x>a[y][1].x;
//	else return a[x][2].x>a[y][2].x;
//}
//
//int main(){
//	freopen("club2.in","r",stdin);
////	freopen(".out","w",stdout);
//	
//	t=read();
//	while(t--){
//		n=read(),ans=0;
//		for(ll i=1;i<=n;++i){
//			for(ll j=0;j<=2;++j)a[i][j].x=read(),a[i][j].id=j;
//			sort(a[i],a[i]+3,cmp1);
//			b[i]=i;
//		}
//		sort(b+1,b+1+n,cmp2);
//		for(ll i=1;i<=n;++i){
//			for(ll j=0;j<=2;++j)c[i][a[b[i]][j].id]=a[b[i]][j].x;
//		}
//		for(ll i=0;i<=n;++i){
//			for(ll j=0;j<=2;++j){
//				f[i][j]=0;
//				for(ll k=0;k<=2;++k)g[i][j][k]=0;	
//			}
//		}
//		
//		for(ll i=1;i<=n;++i){
//			for(ll j=0;j<=2;++j){
//				for(ll k=0;k<=2;++k){
//					if(g[i-1][k][j]+1>n/2)continue;
//					if(f[i-1][k]+c[i][j]>f[i][j]){
//						f[i][j]=c[i][j]+f[i-1][k];
//						for(ll l=0;l<=2;++l)g[i][j][l]=g[i-1][k][l];
//						++g[i][j][j];
//					}
//				}
//			}
//		}
//		for(ll i=0;i<=2;++i){
//			if(f[n][i]>ans){
//				ans=f[n][i];
//				for(int j=0;j<=2;++j)printf("%d ",g[n][i][j]);
//				printf("\n");
//			}
//		}
//		printf("%lld\n",ans);
//	}
//	return 0;
//}



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;

int t,n,a[N][3],c[3],d[3],ans;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void dfs(int u,int sum){
	if(u>n){
		if(sum>ans){
			ans=sum;
			for(int i=0;i<=2;++i)d[i]=c[i];
		}
		return;
	}
	for(int i=0;i<=2;++i){
		if(c[i]+1>n/2)continue;
		++c[i],dfs(u+1,sum+a[u][i]),--c[i];
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	while(t--){
		n=read(),ans=0;
		bool f1=true,f2=true;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=2;++j)a[i][j]=read();
			if(a[1]!=0||a[2]!=0)f1=false;
			if(a[2]!=0)f2=false;
		}
		if(f1){
			for(int i=1;i<=n/2;++i)ans+=a[i][0];
			printf("%d\n",ans);continue;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}	
	return 0;
}

