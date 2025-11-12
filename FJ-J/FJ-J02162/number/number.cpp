#include<iostream>
#include<algorithm>
using namespace std;
int a[4000005],ind=0;
long long m=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[ind]=int(s[i]-'0');
			ind++;
		}
	}
	sort(a+0,a+ind);
	for(int i=ind-1;i>=0;i--)
	{
		cout<<a[i];
		if(i==ind-1&&a[i]==0)return 0;
	}
	return 0;
} 
