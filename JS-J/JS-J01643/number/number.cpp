#include<bits/stdc++.h>
using namespace std;

string s;
long long a[15];

int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	//cout << s << endl;
	for(long long i = 0;i < s.size();i++)
	{
		if(s[i] >= 48 && s[i] <= 57)
		{
			//cout << s[i] << " ";
			a[s[i]-48]++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		//cout << a[i];
		if(a[i] != 0)
		{
			for(long long j = 1;j <= a[i];j++)
			{
				cout << i;
			}
		}
		
		
	}
	return 0;
}
 
