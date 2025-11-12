#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a[10];
char ch[10]={'0','1','2','3','4','5','6','7','8','9'};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int len=s1.size();
	for(int i=0;i<len;i++)
	if(s1[i]>='0'&&s1[i]<='9')
	{
		int x=s1[i]-'0';
		a[x]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		s2+=ch[i];
	}
	cout<<s2<<endl;
	return 0;
}

