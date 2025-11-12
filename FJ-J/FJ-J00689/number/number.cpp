#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),k=1;
	bool f=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=(s[i]-'0');
			k++;
		}
	}
	k--;
	sort(a+1,a+1+k);
	for(int i=1;i<=k;i++)
	{
		if(a[i]!=0)
		{
			f=1;
			break;
		}
	}
	if(f)
	{
		for(int i=k;i>=1;i--)cout<<a[i];
	}
	else cout<<"0";
	return 0;	
} 
