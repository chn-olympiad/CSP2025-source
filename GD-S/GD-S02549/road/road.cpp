#include <bits/stdc++.h>
using namespace std;
long long t,i,j,v,ans,k,n,m,x,y,sum,cnt,p,q;
struct edge{
	long long fr,to,w;	
}a[400005];
vector <edge> s;
long long fa[10104],g[10104];
long long find(long long x){
	if(fa[x]==x){
		return x;
	} 
	fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	for(i=1;i<=m;i++){
		cin>>a[i].fr>>a[i].to>>a[i].w;
	}
	for(i=1;i<=k;i++){
		cin>>p;
		for(j=1;j<=n;j++){
			cin>>g[j];
		}
		if(p==0){
			q++;
			for(j=1;j<=n;j++){
				a[m+j].fr=n+q;
				a[m+j].to=j;
				a[m+j].w=g[j];
			}
			
		}
	}
	m+=q*n;
	n+=q;
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++){
		x=a[i].fr;
		y=a[i].to;
		if(find(x)==find(y)){
			continue;
		}
		fa[find(x)]=find(y);
		s.push_back(a[i]);
		sum+=a[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<sum;
	return 0;
} 
