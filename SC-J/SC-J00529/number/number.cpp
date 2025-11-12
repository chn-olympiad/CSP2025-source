#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],slen;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	slen=s.size();
	for(int i=0,c;i<slen;i++)
	{
		c=s[i]-'0';
		if(c>=0&&c<=9)a[c]++;
	}
//	for(int i=0;i<10;i++)cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=9;i>=0;i--)
	{
		if(a[i]==0)continue;
		for(int j=1;j<=a[i];j++)printf("%d",i);
	}
	return 0;
}