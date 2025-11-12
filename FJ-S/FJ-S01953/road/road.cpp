#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f[100005];
struct node{
	int x,y,z;
}e[N];
bool cmp(const node &t1,const node &t2){
	return t1.z<t2.z;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)f[i]=i;
	for(int i=1; i<=m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[i].x=x;
		e[i].y=y;
		e[i].z=z;
	}
	int ans=0;
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for(int i=1; i<=m; i++){
		int x=e[i].x;
		int y=e[i].y;
		int z=e[i].z;
		if(find(x)==find(y))continue;
		f[find(x)]=f[find(y)];
		ans+=z;
		cnt++;
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
}
/*
4 4 3
1 4 6
2 3 7
4 2 5
4 3 4
*/
