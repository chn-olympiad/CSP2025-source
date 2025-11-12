#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll k,n,a[N]={0};
ll ans=0;
bool vis[N]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	scanf("%lld",&a[1]);
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=a[i]^a[i-1];
	}
	ans=0;
	for(int i=2;i<=n;i++){
		if(vis[i])continue;
		for(int j=1;j<=i;j++){
			if(vis[j])continue;
			if(a[i]^a[j-1] == k){
				for(int u=j;u<=i;u++){
					vis[u]=1;
				}
				ans+=1;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
