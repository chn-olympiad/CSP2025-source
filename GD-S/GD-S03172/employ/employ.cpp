#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=998244353;
string s;
int n,m;
LL ans=1,sum;
int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') sum++;
	}
	for(int i=1;i<=n-sum;i++){
		ans=(ans*i)%MOD;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

