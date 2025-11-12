#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,ans,u,a[N+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=a[i];
	if(k) ans=cnt;
	else ans=cnt/2;
	printf("%d",ans);
	return 0;
}
