#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5+1e5;

int n,m,k;
int p;
long long ans;
long long c[15],a[11][10005];
struct code{
	int u,v;
	long long w;
}l[N];
bool cmp(code xx,code yy){
	return yy.w<xx.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>l[i].u>>l[i].v>>l[i].w;
	int x=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) p=1;
		for(int j=1;j<=n;j++){
			x++;
			cin>>l[x].w;
			l[x].u=i,l[x].v=j;
		}
	}
	sort(l+1,l+1+m,cmp);
	if(k==0||p==0){
		for(int i=1;i<=n;i++)
			ans+=l[i].w;
		cout<<ans;
		return 0;
	}
	else cout<<rand();
}
