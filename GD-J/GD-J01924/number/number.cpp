#include<bits/stdc++.h>
using namespace std;
int a[100005],sum;
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++sum]=s[i]-'0'; 
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
