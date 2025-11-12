#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	unsigned long long ans=1;
	int n,m,nn=0;
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=1;i<=n;++i)if(str[i]!=0)nn++;
	for(int i=1;i<=nn;++i){ans*=i;ans%=998244353;}
	cout<<ans;
	return 0;
}
