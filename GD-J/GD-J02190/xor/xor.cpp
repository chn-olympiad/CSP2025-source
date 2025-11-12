#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,S=(1<<20);
ll n,k,a[N],s[N],vis[S],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	ll last=0;
	vis[0]=1;
	for(int i=1;i<=n;i++){
		if(vis[s[i]^k]){
			ans++;
			for(int j=last;j<i;j++){
				vis[s[j]]=0;
			}
			last=i;
		}
		vis[s[i]]=1;
	}
	printf("%lld",ans);
	return 0;
}
