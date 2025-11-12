#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,k;
long long bian[maxn];
int find(int x){
	if(bian[x]==x){
		return x;
	}
	bian[x]=find(bian[x]);
	return bian[x];
}

struct edge{
	long long u,v,w;
}b[maxn];

bool cmp(edge x,edge y){
	return x.w<y.w;
}
int gh[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	bian[i]=i;

	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	int gddd;
	for(int i=1;i<=k;i++){
		cin>>gddd;
		for(int j=1;j<=n;j++){
			cin>>gh[j];
		}
		for(int j=1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				m+=1;
				b[m].u=j;
				b[m].v=k;
				b[m].w=gh[j]+gh[k];
			}
		}
	}
	
	sort(b+1,b+m+1,cmp);

	for(int i=1;i<=m;i++){
		//cout<<"sv"<<bian[b[i].u]<<" "<<b[i].v<<endl;
		if(find(b[i].u)!=find(b[i].v)){
			
			
			bian[find(b[i].v)]=find(b[i].u);
			
			ans+=b[i].w;
			//cout<<ans<<" "<<b[i].u<<" "<<b[i].v<<"  "<<bian[b[i].u]<<" "<<bian[b[i].v]<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
