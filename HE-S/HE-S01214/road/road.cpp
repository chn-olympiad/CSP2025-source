#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct node{
	int x,y,z;
}s[10050];
int f[10050];
bool cmp(node a,node b){
	return a.z>b.z;
}
int find(int x){
	if(x!=f[x]) return f[x]=find(f[x]);
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m+k;i++){
		f[i]=i;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
	}
	for(int i=1;i<=k;i++){
		int xxs;
		cin>>xxs;
		for(int i=1;i<=n;i++){
			scanf("%d",&s[m+i].z);
			s[m+i].y=m+i;
			s[m+i].x=i;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=m+k;i++){
		if(find(s[i].x)!=find(s[i].y)){
			f[find(s[i].x)]=find(s[i].y);
			ans+=s[i].z;
		}
	}
	cout<<ans;
	return 0;
}
