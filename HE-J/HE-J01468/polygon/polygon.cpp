#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500002];
long long miku,teto;//miku=max teto=tot
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		miku=max(miku,a[i]);
		teto+=a[i];
	}
	miku*=2;
	if(teto>miku)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;//pian fen
}
