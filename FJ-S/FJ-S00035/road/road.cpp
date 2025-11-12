#include<bits/stdc++.h>
using namespace std;
const int N=100100;
bool cmp(int x,int y){
	return x>y;
}
struct node{
	int u,v,w;
}a[N];
int s[11][10010],b[N],c[100100],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;//不成环最短 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		c[i]=a[i].w;
	}
	int p=m;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[p+i];
		}
		p*=2;
	}
	sort(c+1,c+100001,cmp);
	for(int i=1;i<=n-1;i++){
		ans+=c[i];
	}
	return 0;
}

