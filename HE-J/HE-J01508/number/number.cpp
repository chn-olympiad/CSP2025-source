#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long x=strlen(a),y=1;
	
	for(int i=0;i<x;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[y]=a[i]-'0';
			y++;
		}
	} 
	
	sort(b+1,b+y);
	for(int i=y-1;i>=1;i--)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
