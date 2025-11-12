#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m;
string s;
long long c[N],ss[N],sum=0;
bool ok=false;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&c[i]);
	for(int i=0;i<n;i++)
	{
		ss[i]=s[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ss[i]<s[i])
			{
				sum++;
			}
		}
	}
	printf("%lld",sum%998244353);
	return 0;
}
/*

3 2
101
1 1 2


*/
