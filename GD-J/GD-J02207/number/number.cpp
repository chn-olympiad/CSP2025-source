#include<iostream>
#include<string>
using namespace std;
int tong[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			tong[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(tong[i]>0)
		{
			cout<<i;
			tong[i]--;
		}
	}
	cout<<endl;
	return 0;
}
