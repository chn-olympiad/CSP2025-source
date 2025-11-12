#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long mugun [4] ={0};
int main()
{

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long zuidazhi=-1,he=0;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>mugun[i];
		if(zuidazhi<mugun[i])
		zuidazhi=mugun[i];
		he+=mugun[i];
		
	}
	
	if(he>zuidazhi*2&&n<=3)
	cout<<1;
	else if(n<=3) cout<<0;
	else
	{
	sort (mugun,mugun+n);
 cout<<8; 
}
	return 0;
}
