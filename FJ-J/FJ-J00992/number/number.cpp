#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s,ans;
char num[N];
int n;
bool cmp(char c,char d)
{
	return(c>d);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	cin>>s;
	int a=1,aa=s.size();
	for(int i=0;i<aa;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num[a]=s[i];
			a++;	
		}
	}
	sort(num+1,num+a+1,cmp);
	for(int i=1;i<=a;i++)
		cout<<num[i];

	return 0;
}
