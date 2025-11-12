#include<bits/stdc++.h>
using namespace std;
char a[1000050];
int b[1000050],ii=1,al,e;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	al=strlen(a);
	for(int i=0;i<al;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[ii]=a[i]-'0';
			ii++;
		}
	}
	ii--;
	sort(1+b,1+b+ii);
	for(int i=ii;i>=1;i--)
	{
		if(b[i]!=0) e=1;
		if(e==1) printf("%d",b[i]);
	}
	if(e==0) printf("0");
	return 0; 
}
