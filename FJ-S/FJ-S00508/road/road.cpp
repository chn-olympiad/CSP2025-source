#include <bits/stdc++.h>
using namespace std;
struct T1{
	int u,v,w;
}a[1000010];
bool cmp(T1 x,T1 y){
	return x.w<y.w;
}
struct T2{
	int c,a[1010];
}b[1000010];
long long sum=0;
int cs[1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		sum+=a[i].w;
		cs[a[i].u]++;
		cs[a[i].v]++;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++) cin>>b[i].a[j];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=m;i>=1;i--){
		if(cs[a[i].u]>=1&&cs[a[i].v]>=1){
			sum-=a[i].w;
			cs[a[i].u]--;
			cs[a[i].v]--;
		}
	}
	cout<<sum;
	return 0;
}
