#include<bits/stdc++.h>
using namespace std;
char a[1000002];
int b[1000002];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0,f;
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		f=int(a[i]);
		if(f<=57&&a[i]>=48)
		{
			b[++cnt]=f-48;
		}
	}
	sort(b+1,b+cnt+1); 
	for(int i=cnt;i>=1;i--)
	{
		cout<<b[i];
	}
}
