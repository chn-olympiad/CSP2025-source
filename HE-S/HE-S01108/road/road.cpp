#include<bits/stdc++.h>
using namespace std;
struct st{
	int m,r[100001]; 
}v[11];
int a,b,c,mp[1001][1001],l[11],oooo[1001],ans=1e9;
void dfs(int x,int k[11],int cnt,int qug){
	if(qug>=a){
		ans=min(ans,cnt);
		return ;
	} 
	for(int i=1;i<=a;i++){
		if(mp[x][i]!=0){
			int o=mp[x][i];
			mp[x][i]=100001;
			qug++;
			dfs(i,k,cnt+o,qug);
			qug--;
			mp[x][i]=o;
		}
	}
	for(int i=1;i<=c;i++){
		for(int u=1;u<=a;u++){
			if(k[i]==1){
				qug++;
				//int p=v[i].r[u];
				//v[i].r[u]=100001;
				dfs(u,k,cnt+v[i].r[x]+v[i].r[u],qug);
					//v[i].r[u]=p;
				qug--;
			}else{
				k[i]=1;
				qug++;//int p=v[i].r[u];
				//v[i].r[u]=100001;
				dfs(u,k,cnt+v[i].m+v[i].r[x]+v[i].r[u],qug);//v[i].r[u]=p;
				qug--;
				k[i]=0;
			}
	}}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++){
		int x,y;
		cin>>x>>y>>mp[x][y];
	}
	for(int i=1;i<=c;i++){
		cin>>v[i].m ;
		for(int u=1;u<=a;u++){
			cin>>v[i].r[u]; 
		}
	}
	dfs(1,l,0,0);	
	cout<<ans;
} 
