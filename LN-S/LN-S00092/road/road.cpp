#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[10005];
bool cmp(node x,node y){
	return x.u<y.u;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,c[15]={},w[1000005]={},f[100005]={};
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		f[a[i].u]++,f[a[i].v]++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>w[j];
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
	    ans+=a[i].w;
	    for(int j=i+1;j<=n;j++){
			if(a[j].u==a[i].v){i=j;
				break;
				}
			}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
