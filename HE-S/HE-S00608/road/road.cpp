#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,b[1000005];
struct abc{
	int u,v,w;
}a[1000005];
bool cmp(abc x,abc y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	s=s+a[0].w+a[1].w;
	sort(a,a+m,cmp);
	for(int i=0;i<k;i++){
		for(int j=0;j<m;j++){
			cin>>b[i];
		}
		sort(b,b+m);
		s=s+b[0]+b[1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
