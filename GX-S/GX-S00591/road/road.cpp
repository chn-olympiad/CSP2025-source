#include<bits/stdc++.h>
using namespace std;
long long a[10005];
struct node{
	int x,y;
	long long z;
}c[1000005];
bool cmp(node x,node y){
	return x.z<y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>c[i].x>>c[i].y>>c[i].z;
	}
	sort(c+1,c+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(a[c[i].x]==0||a[c[i].y]==0){
			ans+=c[i].z;
			a[c[i].x]=1;
			a[c[i].y]=1;
		}
	}
	cout<<ans;
	return 0;
}
