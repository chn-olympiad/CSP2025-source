#include<iostream>
#include<vector>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::vector<int> a;
	int n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a.push_back(s[i]-'0');
			n++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				a[i]+=a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	return 0;
}
