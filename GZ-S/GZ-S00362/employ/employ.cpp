//GZ-S00362 北京师范大学贵阳附属中学 罗思妤
#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=505;
string s;
long long n,m,c[N],cnt,sum;
bool f[N];
void dfs (long long x,long long y,long long z){
	if (x==n){
		if (z>=m){
			cnt=cnt+1%mod;
		}
		return ;
	}
	for (int i=1;i<=n;i++){
		if (f[i]==1){
			continue;
		}
		if (y>=c[i] || s[x]=='0' || c[i]==0){
			f[i]=1;
			dfs (x+1,y+1,z);
			f[i]=0;
		}else{
			f[i]=1;
			dfs (x+1,y,z+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	cin >>s;
	for (int i=1;i<=n;i++){
		scanf ("%lld",&c[i]);
	}
	sort (c+1,c+1+n);
	dfs (0,0,0);
	printf ("%lld",cnt);
	return 0;
}
