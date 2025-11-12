#include<bits/stdc++.h>
using namespace std;
string a,b;
long long len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b+=a[i];
		}
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	cout<<b;
	return 0;
}
