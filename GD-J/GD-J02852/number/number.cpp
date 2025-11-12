#include<bits/stdc++.h>
using namespace std;
int a[1001000],z;
char s[1001000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			z++;
			a[z]=s[i]-48;
		}
	} 
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=z;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
