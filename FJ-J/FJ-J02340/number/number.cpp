#include<bits/stdc++.h>
using namespace std;
string s,num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s)
		if(i>='0'&&i<='9')
			num+=i;
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--)
		cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
