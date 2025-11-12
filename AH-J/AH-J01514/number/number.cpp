#include<bits/stdc++.h>
using namespace std;
string s;
int b[120];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int n=s.size();
    for(int i=0;i<n;i++)
    {
		if(s[i]>='0' && s[i]<='9')
		{
			b[int(s[i])]++;
		} 
	}
	for(int i='9';i>='0';i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<char(i);
		}
	}
    return 0;
}
