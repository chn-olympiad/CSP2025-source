#include<bits/stdc++.h>
using namespace std;
long long op,l,a[1000005];
string r;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>r;
	for(int i=0;i<r.size();i++)
	{
		if(r[i]>='0'&&r[i]<='9')
		{
			op=r[i]-'0';
			l++;
			a[l]=op;
		}
	}
	sort(a+1,a+l+1);
	if(a[l]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=l;i>=1;i--)
	{
		cout<<a[i];
	}
	
	return 0;
}
