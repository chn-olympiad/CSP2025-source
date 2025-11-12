#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000005],sum=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[sum]=long long(s[i])-48;
			sum++;
		}
	}
	sort(a+1,a+sum);
	for(long long i=sum-1;i>=1;i--)
	{
		cout<<a[i];
	}
	//cout<<1111;
	return 0;
 } 
