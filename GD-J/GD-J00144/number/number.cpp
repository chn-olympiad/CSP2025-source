#include<bits/stdc++.h>
using namespace std;
long long a[1000005],c,d,e,g,k;
char b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	c=strlen(b);
	for(int i=0;i<c;i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			a[++d]=b[i]-'0';
		}
	}
	sort(a+1,a+d+1);
 for(int i=d;i>=1;i--)
 {
 	cout<<a[i];
  } 
  return 0;
 } 
 
