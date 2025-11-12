#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=10010;
const int M=2e6+10;
int n,m,k,ans=1e18,v[N],res,c[20],b[20][N],fa[N],mie;
struct node{
	int x,y,z;
}a[M],e[M];
int findx(int x){
	if(x==fa[x])return x;
	return fa[x]=findx(fa[x]);
}
bool cmp(node x,node y){
	return x.z<y.z;
}
void work(int op){
	for(int i=1;i<=n+1;i++)fa[i]=i;
	sort(e+1,e+m+n*op+1,cmp);
	int cnt=n+op;
	for(int i=1;i<=m+n*op;i++){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		x=findx(x);
		y=findx(y);
		if(x==y)continue;
		cnt--;
		fa[x]=y;
		res+=z;
//		if(v[1]==1&&v[2]==0){
//			cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].z<<"ma\n";
//		}
		if(cnt==1)break;
	}
}
void dfs(int x){
	if(x==k+1){
//		cout<<"kx";
		res=0;
		for(int i=1;i<=m;i++){
			e[i].x=a[i].x;
			e[i].y=a[i].y;
			e[i].z=a[i].z;
		}
		for(int i=1;i<=n;i++)e[m+i].z=1e18;
		int O=0;
		for(int j=1;j<=k;j++){
			if(v[j]){
				O++;
				res+=c[j]; 
				for(int i=1;i<=n;i++){
					e[m+i].x=n+1;
					e[m+i].y=i;
					e[m+i].z=min(e[m+i].z,b[j][i]);
				}
			}
		}
		if(!O)return;
//		cout<<"ok";
		work(1);
//		if(v[1]==1&&v[2]==0)cout<<res<<"e\n";
//		if(res<ans){
//			for(int i=1;i<=k;i++)cout<<v[i]<<" ";
//			cout<<endl;
//		}
		ans=min(ans,res);
		return;
	}
	dfs(x+1);
	v[x]=1;
	dfs(x+1);
	v[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	mie=m;
	for(int i=1;i<=m;i++){
		a[i].x=read(),a[i].y=read(),a[i].z=read();
//		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			b[i][j]=read();
//			cout<<b[i][j]<<" ";
		}
	}
//	work();
//	cout<<res<<endl;
	for(int i=1;i<=m;i++){
		e[i].x=a[i].x;
		e[i].y=a[i].y;
		e[i].z=a[i].z;
	}
	work(0);
//	cout<<res<<"ED\n";
	ans=min(ans,res);
	if(k==0){
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

