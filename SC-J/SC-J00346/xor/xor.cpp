#include<bits/stdc++.h>
using namespace std;
int a[500005]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	cin>>a[1];
	int s=a[1];
	if(s==k)
	{
		cnt++;
		s=0;
	}
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		s=s^a[i];
		if(s==k)
		{
			cnt++;
			s=0;
		}
	}
	cout<<cnt;
	return 0;
 } 