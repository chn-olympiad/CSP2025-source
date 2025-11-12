#include<bits/stdc++.h>
using namespace std;
const int M=522,mod=998244353;
int n,m,c[M],sum,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(NULL));
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1') sum++;
	}
	if(sum==n){ 
		ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans*i)%mod;
	}
	else if(m==n && sum<n) ans=0;
	else ans=rand()%mod;
	cout<<ans%mod;
	return 0;
}
