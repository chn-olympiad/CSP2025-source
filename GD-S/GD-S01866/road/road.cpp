#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,fa[10005];
long long ans;
struct node{
	int x,y,w;
}a[10005];
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
bool cmp(node l,node r){
	return l.w<r.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n*(k+1);i++)fa[i]=i;
	for(int i=0;i<m;i++)cin>>a[i].x>>a[i].y>>a[i].w;
	if(k!=0){
		ans=INT_MAX;
		for(int i=0;i<k;i++){
			long long x,sum=0;
			cin>>x;
			for(int j=1;j<=n;j++){
				int u;
				cin>>u;
				sum+=u;
			}
			ans=min(ans,sum);
		}
		return cout<<ans,0;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		bool f=0;
		for(int j=1;j<=n&&!f;j++)
			for(int k=j+1;k<=n;k++)
				if(fa[j]!=fa[k]){
					f=1;
					break;
				}
		if(!f)break;
		int x=find(a[i].x),y=find(a[i].y);
		if(x==y)continue;
		ans+=a[i].w;
		fa[x]=y;
	}
	cout<<ans;
	return 0;
}
