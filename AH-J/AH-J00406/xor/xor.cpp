#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,j=0,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]^=a[i-1];
	}
	memset(vis,-0x3f,sizeof(vis));
	vis[0]=0;
	for(int i=1;i<=n;i++){
		if(vis[a[i]^k]>=j){
			j=i;
			ans++;
		}
		vis[a[i]]=i;
	}
	printf("%d",ans);
	return 0;
}