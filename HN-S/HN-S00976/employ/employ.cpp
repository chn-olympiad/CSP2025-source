#include<bits/stdc++.h>
using namespace std;
long n,m,ans=1;
long a[10000];
string s;
int main()
{
	freopen("employ.in.txt","r",stdin);
	freopen("employ.out.txt","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
		ans*=a[i];
		else
		ans*=13;
	}
	cout<<ans;
	return 0;
}
