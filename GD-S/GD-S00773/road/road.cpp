#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5,maxk=15;
struct edge{
	int u,v,w;
}e[maxn]={},e1[maxn]={},e2[maxn]={};
int n,m,k,c[maxk]={},a[maxk][maxn]={},f[maxn]={},top=0;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x)
		return x;
	return f[x]=find(f[x]);
}
bool add(int x,int y){
	if(find(x)==find(y))
		return 0;
	f[f[x]]=f[y];
	return 1; 
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<=n+k;i++)
		f[i]=i;
	sort(e,e+m,cmp);
	long long ans=0;
	for(int i=0;i<m;i++){
		int f=0;
		if(add(e[i].u,e[i].v)){
			f++;
			e1[top++]=e[i];
			ans+=e[i].w;
		}
		if(f==n-1)
			break;
	}
	for(int i=0;i<top;i++){
		e2[i]=e1[i];
		e[i]=e1[i];
	}
	for(int i=1;i<=k;i++){
		long long ans1=0;
		int ltop=top;
		for(int j=1;j<=n;j++)
			e2[top++]={i+n,j,a[i][j]};
		int lltop=top;
		sort(e2,e2+top,cmp);
		top=0;
		for(int i1=0;i1<=n+k;i1++)
			f[i1]=i1;			
		for(int j=0;j<lltop;j++){
			int f=0;
			if(add(e2[j].u,e2[j].v)){
				f++;
				e1[top++]=e2[j];
				ans1+=e2[j].w;
				if(ans1+c[i]>=ans)
					break;
			}
			if(f==n-1)
				break;
		}
		ans1+=c[i];
		if(ans1<ans){
			ans=ans1;
			for(int i1=0;i1<top;i1++){
				e2[i1]=e1[i1];
				e[i1]=e1[i1];
			}
		}
		else{
			top=ltop;
			for(int i1=0;i1<top;i1++)
				e2[i1]=e[i1];
		}
	}
	cout<<ans;
	return 0;
}

