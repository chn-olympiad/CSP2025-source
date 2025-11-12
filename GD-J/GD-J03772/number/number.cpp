#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'a')
		{
			a[j]=s[i];
			j++;
		}
	}
	sort(a+0,a+j+1);
	string y;
	for(int k=j;k>=0;k--)
	{
		y+=a[k];
	}
	cout<<y<<endl;
	return 0;
}
