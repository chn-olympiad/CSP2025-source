#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],l[10][1000010],f[1000010],st[100000],sum;
bool cmp(stu a,stu b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x]=x;
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>l[i][0];
		st[i]=1;
		for(int j=1;j<=m;j++){
			cin>>l[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		int x=find(u[i]),y=find(v[i]);
		if(st[u[i]]==0 && st[v[i]]==0){
			if(x!=y){
				f[x]=y;
				sum+=w[i];
			}
		}
		if(st[u[i]]==1 && st[v[i]]==0){
			if(x!=y){
				if(l[u[i]][0]+l[u[i]][v[i]]<w[i]){
					f[x]=y;
					sum+=l[u[i]][0]+l[u[i]][v[i]];
					l[u[i]][0]=0;
				}
				else{
					f[x]=y;
					sum+=w[i];
				}
			}
		}
		if(st[u[i]]==0 && st[v[i]]==1){
			if(x!=y){
				if(l[v[i]][0]+l[v[i]][u[i]]<w[i]){
					f[x]=y;
					sum+=l[v[i]][0]+l[v[i]][u[i]];
					l[v[i]][0]=0;
				}
				else{
					f[x]=y;
					sum+=w[i];
				}
			}
		}
		if(st[u[i]]==1 && st[v[i]]==1){
			if(x!=y){
				if(l[v[i]][0]+l[v[i]][u[i]]<w[i] && l[v[i]][0]+l[v[i]][u[i]]<l[u[i]][0]+l[u[i]][v[i]]){
					f[x]=y;
					sum+=l[v[i]][0]+l[v[i]][u[i]];
					l[v[i]][0]=0;
				}
				else if(l[u[i]][0]+l[u[i]][v[i]]<w[i] && l[u[i]][0]+l[u[i]][v[i]]<l[v[i]][0]+l[v[i]][u[i]]){
					f[x]=y;
					sum+=l[u[i]][0]+l[u[i]][v[i]];
					l[u[i]][0]=0;
				}
				else{
					f[x]=y;
					sum+=w[i];
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
