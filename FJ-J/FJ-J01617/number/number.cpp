#include<bits/stdc++.h>
using namespace std;
string s;
int bucket[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')bucket[0]++;
		if(s[i]=='1')bucket[1]++;
		if(s[i]=='2')bucket[2]++;
		if(s[i]=='3')bucket[3]++;
		if(s[i]=='4')bucket[4]++;
		if(s[i]=='5')bucket[5]++;
		if(s[i]=='6')bucket[6]++;
		if(s[i]=='7')bucket[7]++;
		if(s[i]=='8')bucket[8]++;
		if(s[i]=='9')bucket[9]++;
	}
	for(int i=1;i<=bucket[9];i++)cout<<'9';
	for(int i=1;i<=bucket[8];i++)cout<<'8';
	for(int i=1;i<=bucket[7];i++)cout<<'7';
	for(int i=1;i<=bucket[6];i++)cout<<'6';
	for(int i=1;i<=bucket[5];i++)cout<<'5';
	for(int i=1;i<=bucket[4];i++)cout<<'4';
	for(int i=1;i<=bucket[3];i++)cout<<'3';
	for(int i=1;i<=bucket[2];i++)cout<<'2';
	for(int i=1;i<=bucket[1];i++)cout<<'1';
	for(int i=1;i<=bucket[0];i++)cout<<'0';
	return 0;
}
