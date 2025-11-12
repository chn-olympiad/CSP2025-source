#include<bits/stdc++.h>
using namespace std;
string s;
int sn,yg[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sn=s.size();
	for(int i=0;i<sn;i++)
		if(s[i]>='0'&&s[i]<='9')
			yg[s[i]-48]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=yg[i];j++)
			printf("%d",i);
	return 0;
}

