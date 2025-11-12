#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string b;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]>=(char)97&&s[i]<=(char)122))
		{
			b+=s[i];
		}
	}
	int k=b.size();
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k-1;j++)
		if(b[j]<b[j+1])
		{
			swap(b[j],b[j+1]);
		}
	}
	for(int i=0;i<k;i++)
	{
		cout << b[i];
	}





	return 0;
}
