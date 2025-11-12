#include<bits/stdc++.h> 
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int sum=1;
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[sum]=s[i]-'0';
		    sum+=1;
		}
	}
	sum-=1;
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
