#include<bits/stdc++.h>
using namespace std;
string n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	string b=n;
	int x=b.size();
	for(int i=57;i>=49;i--)
	{
		for(int j=0;j<x;j++)
		{
			if(int(n[j])==int(i)) cout<<i-48;
		}
	}
	return 0;
}
