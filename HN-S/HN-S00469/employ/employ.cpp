#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,d,c[210000];
long long ans;
char s[210000];
bool b[210000];
void dfs(int x,int a){
	if(x==n){
		if(n-a>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=1;
			if(a>=c[i]||s[x+1]=='0'){
				if(n-a<m){
					b[i]=0;
					continue;
				}
				dfs(x+1,a+1);
			}
			else {
				dfs(x+1,a);
			}
			b[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='1') d++;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=100){
		dfs(0,0);
	}
	printf("%lld\n",ans%mod);
	return 0;
}
