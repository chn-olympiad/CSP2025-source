#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int t[10]={};
string s;
cin>>s;
int len=s.size();
for(int i=0;i<len;i++)
{
	if(s[i]>='0'&&s[i]<='9')
	{
		t[s[i]-'0']++;
	}
}
if(t[1]==0&&t[2]==0&&t[3]==0&&t[4]==0&&t[5]==0&&t[6]==0&&t[7]==0&&t[8]==0&&t[9]==0)
{
	cout << 0;
	return 0;
}
for(int i=9;i>=0;i--)
{
	for(int j=t[i];j>=1;j--)
	{
		cout << i;
	}
}
return 0;
}
