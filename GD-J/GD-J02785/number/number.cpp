#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	char arr[s.size()];
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			arr[j]=s[i];
			j++;
		}
	}
	bool b=1;
	for(int y=0;y<j;y++)
	{
		if(arr[y]!='0')
		{
			b=0;
		}
	}
	if(b==1)
	{
		cout<<0;
		return 0;
	}
	string ans="";
	sort(arr,arr+j);
	for(int t=j-1;t>=0;t--)
	{
		ans+=arr[t];
	}
	cout<<ans;
}
//当s中的数字的长度大于long的绝对值时，无法正确。如18d914918ibo18219da09c8z91830918adoiu3不行，但是jifoaijofiyuwiusilh114可以 
