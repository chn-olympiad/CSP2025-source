#include <bits/stdc++.h>
using namespace std;
string my_S;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>my_S;
	sort(my_S.begin(),my_S.end());
	for(int i = my_S.size();i>=0;i--)
	{
		if(my_S[i]>='0' && my_S[i]<='9')
		{
			cout<<my_S[i];
		}
	}
	return 0;
 } 
