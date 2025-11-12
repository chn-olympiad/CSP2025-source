#include<bits/stdc++.h>
using namespace std;
string s;
int arr[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9' && s[i]>='0') arr[s[i]-'0']++;
	}
	int c=0;
	for(int i=9;i>=0;i--)
	{
		if(i==0 && c==0)
		{
			cout << 0;
			break;
		}
		if(arr[i]!=0)
		{
			for(int j=1;j<=arr[i];j++)
			{
				cout << i;
			}
			c=1;
		}
	}
	return 0;	
}
