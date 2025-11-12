#include<bits/stdc++.h>
using namespace std;
int mx;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin>>t;
	int s;
	s=t.size();
	long long b[100005];
	if(s==1)
	{
		cout<<t;
	}
	else
	{
		for(int i=0;i<=t.size();i++)
		{
			if(!(abs(t[i]-'0')>=48&&abs(t[i]-'0')<=74))
			{
				b[i]=t[i]-'0';
				mx++;
			}
		} 
		sort(b,b+mx+1);
		for(int i=mx;i>=1;i--)
		{
			cout<<b[i];
		 }
	}
}
