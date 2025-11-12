#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
string s;
int c=0,j=0,a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if((int)s[i]>=48&&(int)s[i]<=58)
		{
			j++;
		    a[j]=(int)s[i]-48;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--)
	cout<<a[i];
	return 0;
}
