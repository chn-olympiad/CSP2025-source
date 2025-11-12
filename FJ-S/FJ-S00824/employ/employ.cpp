#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long answer=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)answer=answer*i%mod;
	cout<<answer;
	return 0;
}
