#include<bits/stdc++.h>
using namespace std;
struct node{
	int f,t,v;
}a[100000005];
int fa[1005],n,m,k,c[1005];
int mp[10005][10005];

bool cmp(node x,node y){
	return x.v<y.v;
}
int p(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=p(fa[x]);
}
void solve1(){
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].f,&a[i].t,&a[i].v);
		cin>>a[i].f>>a[i].t>>a[i].v;
	}
	sort(a+1,a+m+1,cmp);
	int cnt=1,sum=0;
	for(int i=1;i<=m;i++){
		if(p(a[i].f)!=p(a[i].t)){
			sum+=a[i].v;
			cnt++;
			fa[p(a[i].f)]=p(a[i].t);
			if(cnt==n){
				cout<<sum;
				return ;
			}
		}
	}
}
void solve2(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=1e9+1;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
//		cout<<mp[x][y]<<endl;
		mp[x][y]=min(mp[x][y],z);
		mp[y][x]=mp[x][y];
//		cout<<i;
	}
//	cout<<endl;
	for(int i=1;i<=k;i++){
		int b;
		int f;
//		cout<<i<<endl; 
		scanf("%d",&f);
//		cout<<f;
		for(int j=1;j<=n;j++){
//			cout<<j<<endl;
			scanf("%d",&c[j]);
			if(c[j]==0)b=j;
		}
//		cout<<i<<' '<<n<<endl;
		for(int j=1;j<=n;j++){
//			cout<<mp[j][b]<<' '<<c[j]<<' ';
			mp[j][b]=min(mp[j][b],c[j]);
			mp[b][j]=mp[j][b];
//			cout<<mp[j][b]<<endl; 
		}
//		cout<<b<<endl;
	}
	int cnt=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp[i][j]!=1e9+1){
				a[++cnt]={i,j,mp[i][j]};	
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int cn2=1,sum=0;
	for(int i=1;i<=m;i++){
		if(p(a[i].f)!=p(a[i].t)){
			sum+=a[i].v;
			cn2++;
//			if(p(a[i].f)!=a[i].f)cout<<a[i].f<<' '<<a[i].t<<' '<<p(a[i].f)<<' '<<p(a[i].t)<<endl;
			fa[p(a[i].f)]=p(a[i].t);
//			if(p(a[i].f)!=a[i].f)cout<<a[i].f<<' '<<a[i].t<<' '<<p(a[i].f)<<' '<<p(a[i].t)<<endl;
			if(cn2==n){
				cout<<sum;
				return ;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0)solve1();
	else solve2();
	return 0;
} 
