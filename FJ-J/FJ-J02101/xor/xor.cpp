#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool b=0;
	int n,k;
	cin>>n>>k;
	if(k!=0)b=1;
	
	for(int i = 0 ; i<n;i++)
	{
		cin >>a[i];
		if(a[i]!=1)
		{
			b=1;
		}
	}
	
	if(b==1)
	{
		if(n%2==0)cout << n/2;
		else cout << n/2+1;
	}
	else 
	{
		cout << n/2;
	}
	return 0;
}
