#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int b[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			j++;
			b[j]=a[i]-'0';
		}
	}
	sort(b+1,b+1+j);
	for(int i=j;i>=1;i--)
	{
		cout<<b[i];
	}
	return 0;
}
