#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9)
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<k;i++)
		cout<<a[i];
	return 0;
}
