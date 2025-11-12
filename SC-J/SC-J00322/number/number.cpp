#include<bits/stdc++.h>
using namespace std;
int b[10000001];
string ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;	
	long long t=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{			
			b[t]=a[i]-'0';
			t++;
		}
	}
	sort(b,b+t);
	for(int i=t-1;i>=0;i--)
	{
		ans=ans+char(b[i]+'0');
	}
	cout<<ans<<endl;
	return 0;
} 