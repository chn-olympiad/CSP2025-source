#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],x=1;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=int(s[i]-'0');
			x++;
		}
	}
	sort(a+1,a+1+x);
	for(int i = x;i >1; i--)
	{           
		cout << a[i]; 
	}
	return 0;
}