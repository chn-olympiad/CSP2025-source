#include<bits/stdc++.h>
using namespace std;
long long a[500001],qzh[500001],n,ans,k;
bool vis[500001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		qzh[i]=(qzh[i-1]^a[i]);
		for(int j=1;j<=i;j++){
			if((qzh[i]^qzh[j-1])==k){
				bool f=0;
				for(int z=j;z<=i;z++){
					if(vis[z]){
						f=1;
						break;
					}
					else vis[z]=1;
				} 
				if(!f) ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
} 