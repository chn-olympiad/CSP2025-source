#include <bits/stdc++.h>
using namespace std;
const int N=5e5,M=(1<<20);
int n,k,ans,s[N+10],f[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		s[i]=(s[i-1]^s[i]);
	}
	for(int i=1;i<M;i++)
		f[i]=-(1<<30);
	for(int i=1;i<=n;i++)
		f[s[i]]=ans=max(ans,f[s[i]^k]+1);
	printf("%d",ans);
}
