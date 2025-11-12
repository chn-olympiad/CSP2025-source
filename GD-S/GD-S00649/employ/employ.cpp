#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define MOD 998244353
int c[N];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	cin>>a;
	int q=n;
	for(int i=1;i<=n;i++)
	  cin>>c[i];
	for(int i=1;i<=n;i++)
	  if(c[i]==0)
	    q--;
	long long s=1;
	for(long long i=1;i<=q;i++)
	  {
	  	s=(s*i)%MOD;
	  }
	cout<<s<<endl;
 } 
