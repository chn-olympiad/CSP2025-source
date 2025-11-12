#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],sum,sum2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==0) sum2++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=sum;j++)
		{
			if(a[j]==i)
			{
				cout<<i;
				a[j]=-1;
			}
		}
	}
	return 0;
}
