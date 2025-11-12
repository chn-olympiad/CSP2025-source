#include<bits/stdc++.h>
using namespace std;
const int MAXN=520,mod=998244353;
int n,s[MAXN],m,c[MAXN];
string q;
char x[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",c[i]);
	int ans=1;
	for(int i=n;i>=n-m+1;i--){
		ans*=i;
		ans%=mod;
	}
	printf("%d",ans%mod);
	return 0;
} 
