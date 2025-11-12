#include<bits/stdc++.h>
using namespace std;
string s="",n="";
long long a[10],sum=0,len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum++;
			switch(s[i])
			{
				case '0':
					a[0]++;
					break;
				case '1':
					a[1]++;
					break;
				case '2':
					a[2]++;
					break;
				case '3':
					a[3]++;
					break;
				case '4':
					a[4]++;
					break;
				case '5':
					a[5]++;
					break;
				case '6':
					a[6]++;
					break;
				case '7':
					a[7]++;
					break;
				case '8':
					a[8]++;
					break;
				case '9':
					a[9]++;
					break;
			}
		}
	}
	for(int i=1;i<=sum;i++)
	{
		for(int j=9;j>=0;j--)
		{
			if(a[j]!=0)
			{
				a[j]--;
				n+='0'+j;
				break;
			}
		}
	}
	cout<<n;
	return 0;
}
