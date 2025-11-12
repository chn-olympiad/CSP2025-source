#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,number;
	string a;
	cin>>n>>m>>a;
	int s[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		number*=i;
		number%=998244353;
	}
	cout<<number;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//998244353
