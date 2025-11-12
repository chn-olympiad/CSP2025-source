#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,x,y,l;
int a[N];
int size[N];
int b[N];
int f[1010][1010];
int c[15];
struct node{
	int x,y,k;
};
int find(int x){
	if(a[x]==x)return x;
	int boss=find(a[x]);
	a[x]=boss;
	return boss;
}
void join(int x,int y){
	if(size[x]<size[y]){
		a[x]=y;
		size[y]+=size[x];
		size[x]=0;
	}
	else {
		a[y]=x;
		size[x]+=size[y];
		size[y]=0;
	}
}
vector<node>e;
bool cmp(node x,node y){
	return x.k<y.k;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=0x3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y>>l;
		node z;
		z.x=x;
		z.y=y;
		z.k=l;
		e.push_back(z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++){
			for(int r=j+1;j<=n;j++){
				f[j][r]=min(f[j][r],b[j]+b[r]);
			}
		}
		for(int j=1;j<=n;j++){
			for(int r=j+1;r<=n;r++){
				node z;
				z.x=j;
				z.y=r;
				z.k=f[j][r];
				e.push_back(z);
			}
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
		size[i]=1;
	}
	int ans=0;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		node z=e[i];
		x=z.x;
		y=z.y;
		l=z.k;
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			join(fx,fy);
			ans+=l;
		}
	}
	cout<<ans<<endl;
}
