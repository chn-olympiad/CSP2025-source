#include<bits/stdc++.h>
using namespace std;
string n;
long long a[1000099],c=0,k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		if((48<=int(n[i]))&&(int(n[i])<=57))
		{
			a[c]=int(n[i])-48;
			c++;
		}
	}

	sort(a+1,a+c);
	for(int i=c-1;i>0;i--)
		cout<<a[i];
	return 0;
}
