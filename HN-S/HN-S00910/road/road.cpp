#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,k;
int u[N],v[N],w[N],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k<=0){
		for(int i=1;i<=m;i++){
			cin>>u[i]>>v[i]>>w[i];
			ans += w[i];
			/*for(int j=1;j<=n;j++){
				if(u[j]==v[i]||v[j]==u[j]){
					continue;
				}else{
					ans += w[i];	
				}
			}*/
		}
		cout<<ans;
	}else{
		
	}
	return 0;
}
