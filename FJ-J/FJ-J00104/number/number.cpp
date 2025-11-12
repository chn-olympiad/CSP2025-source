#include<bits/stdc++.h>
using namespace std;
long long c[1145141],ii = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long b = a.size();
	for(long long i=0;i<b;i++)
	{
		if(a[i] >=  '0'&&a[i] <= '9')
		{
			c[ii]  = a[i] - '0';
			//cout<<"c[ii]"<<c[ii]<<endl;
			//cout<<"a[i]"<<a[i]<<endl;
			ii++;	
		}
	}
	sort(c,c+ii);
	//cout<<ii<<endl;
	for(long long i=ii-1;i>=0;i--)
	{
		cout<<c[i];
	}
	//cout<<"b="<<b<<endl;
	//cout<<endl<<"ii="<<ii<<endl;
	return 0;
}
