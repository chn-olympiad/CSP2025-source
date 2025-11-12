#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	for(int q=s.length()-1;q>=0;q--)
	{
		if(isdigit(s[q]))
		{
			cout<<s[q];
		}
	}
	return 0;
}
