#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int a;
int _0,_1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a)
		{
			_1++;
		}
		else
		{
			_0++;
		}
	}
	//cout<<_1<<" "<<_0;
	if(k==0)
	{
		cout<<_0+_1/2;
	}
	else
	{
		cout<<_1;
	}
	return 0;
} 
