#include<bits/stdc++.h>
using namespace std;
string str;
int x[1000001],sum=0;
bool cmp(int n,int m)
{
	return n>m;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if('0'<=str[i]&&str[i]<='9')
		{
			sum++;
			x[sum]=(int)(str[i])-(int)('0');
		}
	}
	sort(x+1,x+1+sum,cmp);
	for(int i=1;i<=sum;i++)
	{
		cout<<x[i];
	}
	return 0;
} 
