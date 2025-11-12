#include<bits/stdc++.h>
using namespace std;

string s;
int m=0;
int a[1001010];

void swapt(int x)
{
	for(int i=1;i<=x-1;i++)
		for(int j=i+1;j<=x;j++)
			if(a[j]<a[i])
			{
				int t=a[j];
				a[j]=a[i];
				a[i]=t;	
			} 
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			m++;
			a[m]=s[i]-'0';	
		}
	swapt(m);
	for(int i=m;i>=1;i--)
		cout<<a[i];
	return 0;
}
