#include<bits/stdc++.h>
#define f(i,a,n) for(int i=a;i<=n;i++)
#define mod 998244353
using namespace std;
int n,m,c[505],cnt;
string s;
int fx(int x){
	int s=1;
	f(i,2,n)s=s*i%mod;
	return s;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	f(i,1,n)cin>>c[i];
	sort(c+1,c+n+1);
	for(auto i:s)if(i=='1')cnt++;
	if(n==m||m==1||cnt==n){
		cout<<fx(n);
	}
	return 0;
}
