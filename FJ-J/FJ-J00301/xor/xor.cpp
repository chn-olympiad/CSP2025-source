#include <bits/stdc++.h>
using namespace std;

int n,k,a[200005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool ok = 1;
	int cnt1=0,cnt0=0;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1){cnt0++;}
		else cnt1++;
		
	}
	if(k==0)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1){cnt0++;i++;}
		}
		cout<<cnt0;
	}
	else if(k==1)
	{
		cout<<cnt1;
	}
	return 0;
}
//%%%艾伦·图灵之神%%%
//%%%冯·诺依曼之神%%%
//%%%%%%%%%%%%%%%%%%%%
//佑我此题25分 
