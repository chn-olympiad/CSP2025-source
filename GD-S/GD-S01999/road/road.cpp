#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int n,m,k;
int p[N];
int nc=1,nb;//nc为已经联通的城市，nb为已经建造的城市 

long long ans;

struct node{
	int u,v;
	long long w; 
}a[N+N];

bool cmp(node x,node y){
	return x.w<y.w;
}

int f(int x){
	if(p[x]!=x) p[x]=f(p[x]);
	return p[x];
}

void init(){
	for(int i=0;i<N;i++) p[i]=i;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=0;i<k;i++){
		long long val;
		cin>>val;
		long long n1v;
		cin>>n1v;
		n1v+=val;
		for(int j=1;j<n;j++){
			a[m+(i*10)+j-1].u=1;
			a[m+(i*10)+j-1].v=j;
			cin>>a[m+(i*10)+j-1].w;
			a[m+(i*10)+j-1].w+=n1v;
		}
	}
	init();
	sort(a,a+(n*10)+m,cmp);
	for(long long i=0;i<m+(n*10);i++){
		int fa=f(a[i].u);
		int fb=f(a[i].v);
		if(fa!=fb){
			ans+=a[i].w;
			p[fa]=fb;
			nc++;
			//cout<<"ps   "<<fa<<"   "<<fb<<"\n";
		}
		if(nc==n){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	//if(nc<n)
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
