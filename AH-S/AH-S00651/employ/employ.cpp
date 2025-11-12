#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[100005];
int p[15]={0,1,2,3,4,5,6,7,8,9,10};
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int ans=0;
	if(n<=10)
	do{
		int x=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||x>=c[p[i]]) x++;
		if(n-x>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	else{
		int x=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||x>=c[p[i]]) x++;
		if(n-x>=m) ans++;
		for(int i=1;i<=n;i++)
			ans*=i,ans%=998244353;
	}
	cout<<ans<<'\n';
	return 0;
}
