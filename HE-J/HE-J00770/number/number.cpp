#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=s.length();
	vector<int> arr;
	for(int i=0;i<a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
	    	int q=(int)(s[i]-'0');
			arr.push_back(q);
		}
	}
	a=arr.size();
	int v=10;
	for(int i=0;i<a;i++)
	{
		for(int j=i;j<a;j++)
		{
			if(arr[j]>arr[i])
			{
				v=arr[i];
				arr[i]=arr[j];
				arr[j]=v;
			}
		}
	}
	a=arr.size();
	for(int i=0;i<a;i++)
	{
		cout<<arr[i];
	}
	return 0;
}
