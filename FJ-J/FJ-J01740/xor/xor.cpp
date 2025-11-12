#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
bool v[N];
int n,k,a[N],b[N],cnt,ans;
void dfs(int t,int m,int b[N]) {
	if(t>m) {
		int y=b[1];
		for(int i=2;i<t;i++) 
			y^=b[i];
		if(y==k) cnt++;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(!v[i]) {
			b[t]=i;
			dfs(t+1,m,b);
		}
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(k==0||k==1) {
		for(int i=1;i<=n;i++) 
			if(a[i]==k) ans++;
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int i=1;i<=n;i++) v[i]=b[i]=0;
		dfs(1,i,b);
		ans=max(ans,cnt);
	}
	printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
