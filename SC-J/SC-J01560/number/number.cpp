#include<iostream>
using namespace std;
int a[15];
string s;
int main()
{
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		while (a[i]!=0)
		{
			cout<<i;
			a[i]--;
		}
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}

