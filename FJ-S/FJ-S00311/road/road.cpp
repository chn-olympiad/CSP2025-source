#include<bits/stdc++.h>
using namespace std;
struct qp{
	int u,v,w;
}a[2000006];
int n,m,k,c,t,b[1000005],f[1000005];
long long sum;
bool cmp(qp x,qp y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]=x) return x;
	f[x]=find(f[x]); 
	return f[x];
}
void hebing(int x,int y){
	f[x]=find(f[x]);
	f[y]=find(f[y]);
	f[x]=f[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    t=m;
    for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++){
    	int x;
    	cin>>x;
    	for(int j=1;j<=n;j++) cin>>b[j];
		for(int j=1;j<=n;j++){
    		cin>>b[j];
    		if(i!=j){
    			a[++t].w=b[j]+x;
    			a[t].u=i;
    			a[t].v=j;
			} 
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=t;i++){
	    if(find(f[a[i].u])==find(f[a[i].v])) continue;
	    hebing(a[i].u,a[i].v);
	    sum+=a[i].w;
	    c++;
	    if(c==n-1){
	    	cout<<sum;
	    	return 0;
		}
	}
    return 0;
}