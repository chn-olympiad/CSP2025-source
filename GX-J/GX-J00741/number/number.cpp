#include<bits/stdc++.h>
using namespace std;
string ch;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>> ch;
	int len=ch.size();
	for(int i=0;i<len;i++)
		if(ch[i]<='9'&&ch[i]>='0')
		{
			int x=ch[i]-'0';
			a[x]++;
		}
	for(int i=9;i>=0;i--)
		if(a[i]>0)
			while(a[i]--) cout<< i;
	return 0;
}
