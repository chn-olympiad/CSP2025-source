#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0,b;
	cin>>s;
	b=s.size();
	int c[b+5]={0};
	int d=0;
	for(int i=0;i<b;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			d++;
			c[d]=s[i]-'0';
		}
	}
	sort(c+1,c+d+1);
	reverse(c+1,c+d+1);
	for(int i=1;i<=d;i++)
	  cout<<c[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
