#include<bits/stdc++.h>
using namespace std;
string a;
int b[100005],s=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[s]=(int)(a[i]-'0');
			s++;
		}
	}
	sort(b+1,b+s+1);
	for(int i=s;i>=2;i--)
	{
		cout<<b[i];
	}
}
