#include <bits/stdc++.h>
using namespace std;
struct s{
	long long u,v,w;
	bool f;
}edge[5000001];
long long c[11],fl[11],fa[10001],chf[10001],cht[10001];
bool cmp(s a,s b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		edge[i].f=0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	if(k==0){
		stable_sort(edge+1,edge+m+1,cmp);
		long long sum=0,ans=0;
		for(int i=1;i<=m;i++){
			if(fa[find(edge[i].u)]!=find(edge[i].v)){
				fa[find(edge[i].u)]=find(edge[i].v);
				ans+=edge[i].w;
				sum++;
			}
			if(sum==n-1){
				break;
			}
		}
		cout<<ans;
	}
	else{
	    long long d[10001]={0};
		long long cnt=1,sum=0,ans=0;
		for(int i=1;i<=k;i++){
		    cin>>c[i];
			for(int j=1;j<=n;j++){
		    	cin>>d[j];
		    	for(int k=1;k<j;k++){
		    		if(j!=k){
		    			edge[m+cnt].u=j,edge[m+cnt].v=k,edge[m+cnt].w=d[j]+d[k];
		    			if(c[i]!=0){
		    				edge[m+cnt].f=i;
						}
						cnt++; 
					}
				}
		    }
		}
		stable_sort(edge+1,edge+m+cnt+1,cmp);
		for(int i=1;i<=m+cnt;i++){
		    if(fa[find(edge[i].u)]!=find(edge[i].v)){
		    	if(edge[i].f==0){
		    		fa[find(edge[i].u)]=find(edge[i].v);
				    ans+=edge[i].w;
				    sum++;
				} 
		    }
			if(sum==n-1){
				break;
			}
		}
		cout<<ans;
	}
	
} 
