#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
const int N=2e4+5;
int n,m,k,p;
long long g[20][N],f[N];
long long sum;
vector<pair<int,int>>v[N];
struct st{
	int x,y,z;
}a[M];
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
void build(){
	int cnt=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x=fd(a[i].x),y=fd(a[i].y);
		if(x==y)continue;
		cnt++;
		f[x]=y;
		v[a[i].x].push_back({a[i].y,a[i].z});
		v[a[i].y].push_back({a[i].x,a[i].z});
		sum+=a[i].z;
		if(cnt==n-1)break;
	}
}

bool cmp(st a,st b){
	return a.z<b.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[i]={x,y,z};
	}
	sort(a+1,a+m+1,cmp);
	bool flag=0;long long mnx=9e18;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>g[i][j];
			if(j>0&&g[i][j]!=0)flag=1;
		}
		mnx=min(mnx,g[i][0]);
	}
	build();
	if(k==0){
		cout<<sum;
		return 0;
	}
	if(flag==0){
		cout<<min(mnx,sum);
		return 0;
	}
	
	return 0;
} 
