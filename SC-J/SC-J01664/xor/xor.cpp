#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,pos;
int ha=1e7;
long long a[N],s[N],vis[N],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n>1e4){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]==k) ans++;
		}
		cout<<ans;
		return 0;
	} 
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			vis[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(vis[j]==1){
				break;
			}
			if(s[i-1]^s[j]==k){
				vis[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		
		if(vis[i]){
			pos=vis[i];
			
		}
		if(pos==i) ans++;
	}
	printf("%lld",ans);
	return 0;
}