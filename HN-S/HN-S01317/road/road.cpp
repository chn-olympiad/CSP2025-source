#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
struct qwq{
	int u,v,w;
}a[N];
bool cmp(qwq x,qwq y){
	return x.w<y.w;
}
int c[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int j=1;j<=k;j++){
		cin>>c[i];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	sort(a+1,a+m+1,cmp);
	int ans=0,sum=0,minn=1e9;
	for(int i=1;i<=m;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
