#include<bits/stdc++.h>
using namespace std;
long long n,m,k,d[15][10007],dep[10007],fa[10007],ans,s;
struct node{
	long long u,v,w;
}a[10000007];
bool cmp(node s1,node s2){
	return s1.w<s2.w;
}
void init(){
	for(int i=1;i<=n;i++){
		dep[i]=1;
		fa[i]=i;
	}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx==ry)return;
	if(dep[rx]<dep[ry]){
		fa[rx]=ry;
	}else{
		fa[ry]=rx;
		if(dep[rx]==dep[ry]){
			dep[rx]++;
		}
	}
}
void kruskal(){
	init();
	for(int i=1;i<=m;i++){
		long long x=a[i].u;
		long long y=a[i].v;
		if(find(x)==find(y))continue;
		merge(x,y);
		ans+=a[i].w;
	//	cout<<x<<" "<<y<<" "<<a[i].w<<endl;
		s++;
		if(s==n-1)return;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>d[i][0];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	if(k!=0){
		int s=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					s++;
					a[s+m].u=j;
					a[s+m].v=x;
					a[s+m].w=d[i][0]+d[i][j]+d[i][x];
				}
			}
		}
		m=s+m;
	}
	sort(a+1,a+1+m,cmp);
	kruskal();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
