#include<iostream>
#include<cstring>
using namespace std;

string s;
int h[15];

int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	
	cin>>s;
	int n = s.size();
	
	for(int i=0;i<n;i++)
	{
		if(s[i] >= 48 && s[i] <= 57)
		{
			h[ int(s[i]-48) ] ++;
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=h[i];j++)
		{
			cout<<i;
		}
	}
	
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
