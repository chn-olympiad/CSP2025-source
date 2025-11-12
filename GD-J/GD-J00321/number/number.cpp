#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+1;
long long a[N],sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	memset(a,0,sizeof(a));
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++sum]=s[i]-'0';
		}
	}
	sort(a+1,a+1+sum);
	if(a[sum]==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=sum;i>=1;i--)
		printf("%lld",a[i]);
	return 0;
} 
