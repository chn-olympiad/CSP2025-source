#include<bits/stdc++.h> 
using namespace std;
char s[1000005];
int a[1000005],n,i,o;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(i<=1000000)
	{
		cin>>s[i];
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[o]=s[i]-'0';
			o++;
		}
		i++;
	}
	sort(a,a+o,cmp);
	for(int i=0;i<o;i++)
	{
		cout<<a[i]; 
	}
	return 0;
}
