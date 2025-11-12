#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,a[510],t,b[510],c[510],v;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
	t+=s[i]-48;
	if(t==n){
		ll u=1;
		for(int i=2;i<=n;i++)
		u=u*i%mod;
		printf("%lld",u);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
	b[i]=i;
	do{
		ll u=0;
		for(int i=1;i<=n;i++)
		c[i]=a[b[i]];
		for(int i=0;i<n;i++){
			if(s[i]=='0'||c[i+1]<=0){
				if(s[i]=='0')c[i+1]=0;
				for(int j=i+2;j<=n;j++)
				c[j]--;
			}
		}
		for(int i=1;i<=n;i++)
		if(c[i]>0)u++;
		if(u>=m)v=(v+1)%mod;
	}while(next_permutation(b+1,b+1+n));
	printf("%lld",v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
