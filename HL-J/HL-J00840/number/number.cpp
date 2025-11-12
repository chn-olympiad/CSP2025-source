#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int i=0;
	int m=s.size();
	for(int j=0;j<m;j++)
	{
		if(s[j]>='0' and s[j]<='9')
		{
			char c;
			c=s[j];
			a[i]=int(c)-48;
			i++;
		}
    }
    sort(a,a+i);
    for(int j=i-1;j>=0;j--)
    {
    	cout << a[j];
	}
	return 0;
}
