#include<bits/stdc++.h>
using namespace std;
struct N{
	int x,y,z;
}a[100001];
int n,m,k,x,y,z,fx,fy,w,sum,q,f[100001];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
inline bool cmp(N a,N b){
	return a.x<b.x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[++w]={x,y,z};
	}
//	cout<<"1-----\n";
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>y;
			a[++w]={x,j,y};
		}
	}
//	cout<<"2-----\n";
	sort(a+1,a+w+1,cmp);
//	cout<<"3-----\n";
	for(int i=1;i<=w;i++){
		fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy){
			f[fx]=fy;
			sum+=a[i].z;
			q++;
		}
		if(q>=n)break;
//		cout<<"I"<<i<<"I\n";
	}
	cout<<sum;
	return 0;
}
