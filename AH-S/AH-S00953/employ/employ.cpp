#include <bits/stdc++.h>
using namespace std;

long long n,m;
string s;
long long ar[505];
long long flag=1;
long long cnt=0;


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&ar[i]);
		if(s[i-1]=='0') flag=0;
		if(ar[i]==0) cnt++;
	}
	if(cnt>n-m){
		puts("0");
		return 0;
	}
	if(flag==1){
		for(long long i=1;i<=m;i++){
			flag*=n-cnt-i+1;flag%=998244353;
		}
		long long flag2=1;
		for(long long i=1;i<=n-m;i++){
			flag2*=i;flag2%=998244353;
		}
		printf("%lld",(flag*flag2)%998244353);
	}
	for(int i=1;i<=n;i++){
		//dfs(i,1);
	}
	
	return 0;
}
