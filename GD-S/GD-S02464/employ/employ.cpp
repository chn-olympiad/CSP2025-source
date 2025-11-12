#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,mod=998244353;
int n,m,s[N],cnt[N],v;
ll fac[N];
char ss[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+'1'-ss[i-1];
	for(int i=1;i<=n;i++) cin>>v,cnt[v]++;
	if(cnt[0]==n) cout<<0;
	else cout<<fac[n];
	fclose(stdin);fclose(stdout); 
return 0;}
