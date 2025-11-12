#include<bits/stdc++.h>
using namespace std;
string s;
int a[100006];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i+1]=s[i]-48;
		}
		else 
		{
			a[i+1]=-1;
		}
	}
	sort(a+1,a+len+1);
	if(a[len]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=len;i>=1;i--)
	{
		if(a[i]!=-1) cout<<a[i];
	}

	return 0;
}

