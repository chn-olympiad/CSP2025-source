#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	long long a,b,c,d;
	vector<long long> v;
	vector<long long> s;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		cin>>d;
		v.push_back(d);
	}
	for(int i=0;i<a;i++)
	{
		c=v[i]^b;
		s.push_back(c);
	}
	
		if(s[1-1]>=s[1])
		{
			cout<<s[1-1];
		}
		else
		{
			cout<<s[1];
		}

	
	return 0;
}
 
