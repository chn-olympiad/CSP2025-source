#include<bits/stdc++.h>
using namespace std;
int n,m,p[11],ans,c[11];
bool vis[11];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char t;
		cin>>t;
		vis[i]=t-'0';
	}
	for(int i=1;i<=n;++i) cin>>c[i],p[i]=i;
	do{
		int fail=0,t=0;
		for(int i=1;i<=n;++i){
			if(c[p[i]]<=fail||!vis[i]){
				++fail;
			}else{
				++t;
			}
		}
		ans+=(t>=m);
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
