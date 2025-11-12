#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=2e6+5;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define qwe(i,l,r) for(int i=l;i<=r;i++)
#define ewq(i,r,l) for(int i=r;i>=l;i--)
int n,m,k,ans=1e18+9,sum,tot,c[N],p[15][N],f[N];//id 返回原边编号 
vector<int>t[15];//连新点的点集 
int asd=1;
struct add{
	int u,v,w;
}a[M],b[M];
bool cmp(add x,add y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
inline int read(){
	char ch;
	int qwq=0,op=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')op=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		qwq=(qwq<<1)+(qwq<<3)+ch-'0';
		ch=getchar();
	}
	return op*qwq;
}
void solve(){
	n=read(),m=read(),k=read();
	qwe(i,1,n)f[i]=i;
	qwe(i,1,m){
		b[i].u=read();b[i].v=read();b[i].w=read();
	}
	qwe(i,1,k){
		c[i+n]=read();
		if(c[i+n]!=0)asd=0;
		qwe(j,1,n){
			p[n+i][j]=read();
			if(p[n+i][j]!=0)asd=0;
		}
	}
	if(asd){
		tot=m,sum=0;
		qwe(i,1,m)a[i]=b[i];
		qwe(j,1,k){
			qwe(i,1,n){
				a[++tot].u=n+j,a[tot].v=i,a[tot].w=p[n+j][i];
			}
			sum+=c[n+j];
		}
		qwe(i,1,n+k+1)f[i]=i;
		sort(a+1,a+1+tot,cmp);
		qwe(i,1,tot){
			int u=a[i].u,v=a[i].v;
			if(find(u)==find(v))continue;
			f[find(u)]=find(v);
			sum+=a[i].w;
		}
	//	cout<<" "<<sum<<"\n";
		ans=min(ans,sum);
		cout<<ans<<"\n";
		return;
	}
	for(int s=1;s<=(1<<(k-1));s++){
		tot=m,sum=0;
		qwe(i,1,m)a[i]=b[i];
		qwe(j,1,k){
			if(s&(1<<(j-1))){
				qwe(i,1,n){
					a[++tot].u=n+j,a[tot].v=i,a[tot].w=p[n+j][i];
				}
				sum+=c[n+j];
			}
		}
		qwe(i,1,n+k+1)f[i]=i;
		sort(a+1,a+1+tot,cmp);
		qwe(i,1,tot){
			int u=a[i].u,v=a[i].v;
			if(find(u)==find(v))continue;
			f[find(u)]=find(v);
			sum+=a[i].w;
		}
	//	cout<<" "<<sum<<"\n";
		ans=min(ans,sum);
	//	cout<<s<<"\n";
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)solve();
	return 0;
}
/*
先跑原图->用过的边打标->跑加点->考虑是否更优 
*/
