#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,k;
int a[N];

int main()
{		
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	
	cin>>n>>k;

	for(int i=1;i<=n;i++)cin>>a[i];

	int num=-1,ans=0;

	for(int i=1;i<=n;i++)
	{
		if(num==-1)num=a[i];
		else num^=a[i];
		if(a[i]==k)
		{
			++ans;
			num=-1;
		}
		else if(num==k)
		{
			++ans;
			num=-1;
		}	
	}

	cout<<ans;
	
	return 0;
}

