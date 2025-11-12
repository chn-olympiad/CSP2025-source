#include <bits/stdc++.h>
#define ll long long
#define p 998244353
using namespace std;
int n,a[505],b[505],ans,m,k;
char s[505];
bool fl;
ll tmp[505],cnt;
bitset<505> vis;
inline void ck(){
	int k=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(!(s[i]^48)||a[b[i]]<=k) k++;
		else cnt++;
	}
	if(cnt>=m) ans++;
} 
void dfs(int x){
	if(x>n){
		ck();
		return ;
	}
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=1;
		b[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!(s[i]^48)) fl=1;
	} 
	sort(a+1,a+1+n);
	if(m==1){
		cnt=tmp[0]=1;
		for(int i=1;i<n;i++) tmp[i]=tmp[i-1]*i%p;
		for(int i=1;i<=n;i++) if(s[i]^48){
			k++;
			for(int j=n;j;j--){
				if(a[j]<=i-1){
					cnt=cnt*(j-k+1)%p;
					break;
				} 
				ans=(ans+tmp[n-k]*cnt)%p;
			}
		}
	}
	else if(m==n){
		if(!fl&&a[1]){
			ans=1;
			for(int i=1;i<=n;i++) ans=1ll*ans*i%p;
		} 
	}
	else dfs(1);
	printf("%d",ans);
	return 0;
}
