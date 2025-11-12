#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

void printVectorInt(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	vector<int>aaa;
	int ans=0;
	for(int i=0;i<=str.size()-1;i++)
	{
		if(  ( (int)str[i]>=48   )&&   ((int)str[i]<=57   ))
		{
			aaa.push_back(str[i]-48);
		}
	}

	sort(aaa.begin(),aaa.end());

	int MAX=aaa.size()-1;
	int SHI=1;
	for(int i=1;i<=aaa.size()-1;i++)
	{
		SHI=SHI*10;
	}
	for(int i=MAX;i>=0;i--)
	{

		ans=ans+aaa[i]*SHI;
		SHI=SHI/10;

	}
	cout<<ans<<endl;
	return 0;

}
