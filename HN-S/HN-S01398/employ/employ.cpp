#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1e9+10;
int patient[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int flag=1;
	for(int i=0;i<n;i++)if(s[i]=='0')flag=0;
	if(flag){
		for(int i=1;i<=n;i++)cin>>patient[i];
		int ans=1;
		for(int i=1;i<=n;i++)ans*=i%998244353;
		cout<<ans;
		return 0;
	}
	return 0;
}

