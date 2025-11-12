#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const int mod=998244353;
int a[N];
int n,k;
bool vis[N];
ll ans;
/*inline void init() {
	lg[0]=-1; lg[1]=0;
	for(int i=2;i<=N;i++) {
		lg[i]=lg[i>>1]+1;
	}
}
*/
void dfs(int pos,int tot,int maxx,int sum)
{
	if(tot==k) {
		if(sum>maxx*2) ans++;
		return ;
	}
	for(int i=pos;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			dfs(i,tot+1,max(maxx,a[i]),sum+a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]); //b[i]=a[i]+b[i-1];
	
	//init();
	
	///for(int j=1;j<=lg[n];j++) {
	//	for(int i=1;i+(1<<j)-1<=n;i++) {
	//		f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	//	}
	//}
	
	/*for(int i=3;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int l=j-i+1,r=j;
			int sum=b[r]-b[l-1];
			int len=lg[r-l+1];
			int maxx=max(f[l][len],f[r-(1<<len)+1][len]);
			if(sum>(maxx*2)) ans++;
		}
	}
	*/
	
	for(int i=3;i<=n;i++)
		k=i,dfs(1,0,0,0);
	
	printf("%lld",ans%mod);
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
