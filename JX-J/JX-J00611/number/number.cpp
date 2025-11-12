#include<bits/stdc++.h>
using namespace std;
int a[1000001],k=0;
int cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001];
	cin>>s;
	for(long unsigned int i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+0,a+k,cmp);
	for(int i=0;i<k;i++)
		cout<<a[i];
}
