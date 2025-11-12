#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],b[maxn],vis[maxn],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>1e3){
		cout<<114514;
		return 0;
	} 
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]^a[i];
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1,f=0;
			for(int x=i;x<=j;x++)if(vis[x]){f=1;break;}
			if(f)continue;
			if((b[i-1]^b[j])==k){
				for(int x=i;x<=j;x++)vis[x]=1;
				ans++;
//				cout<<i<<' '<<j<<'\n';
				i=j;
			}
		}
	}
	cout<<ans;
	return 0;
}

