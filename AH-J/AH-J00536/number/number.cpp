#include<bits/stdc++.h>
using namespace std;
#define ll long long
string str;
inline void read()
{
	char ch=getchar_unlocked();
	while(ch!=EOF)
	{
		if(ch>='0' && ch<='9')
			str=str+ch;
		ch=getchar_unlocked();
	}
}
int t[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	read();
	int len=str.size();
	for(int i=0;i<len;i++)
		t[(int)(str[i]-'0')]++;
	str="";
	for(int i=9;i>=0;i--)
		for(int j=1;j<=t[i];j++)
			str=str+(char)(i+'0');
	cout<<str<<"\n";
	
	return 0;
}
/*
Luogu uid=1383031
达瓦里氏好呀
*/
