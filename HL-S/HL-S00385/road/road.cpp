#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e5+10;
int u[N],v[N],w[N];
bool vis[N];
int f(){
	bool flag=0;
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			flag=1;
			break;
		}
	}
	if(flag==0) return 0;
	int ans=0;
	for(int i=1;i<=m;i++){
		if(vis[i]==0){
			for(int j=1;j<=m;j++){
				if(u[j]==i || v[j]==i){
					ans+=w[j];
					vis[j]=1;
					break;
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	cout <<f();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

