#include<bits/stdc++.h>
using namespace std;
int i=0,l=0,a[10000001]={0},t=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i+1]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+1+t);
	while(t>=1&&a[t]==0)
	{
		t--;
	}
	for(;t>=1;t--)
	{
		cout<<a[t];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
