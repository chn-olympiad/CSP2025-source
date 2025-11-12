#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	if(len==1)cout<<s;
	if(len<=10&&len>1)cout<<s;
	if(len<=100&&len>10)cout<<s;
	if(len<=1000&&len>100)cout<<s;
	if(len<=100000&&len>1000)cout<<s;
	if(len<=1000000&&len>100000)cout<<s;
	return 0;
}
