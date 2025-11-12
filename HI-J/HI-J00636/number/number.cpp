#include<bits/stdc++.h>
using namespace std;
string s,b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	long long l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[k]=s[i];
			k++;
		}
	}
	for(int i=0;i<l-1;i++)
	{
		for(int j=0;j<l-1-i;j++)
		{
			if(b[j]<b[j+1]) swap(b[j],b[j+1]);
		}
	}
	for(int i=0;i<k;i++)
	{
		cout<<b[i];
	}
	return 0; 
}
