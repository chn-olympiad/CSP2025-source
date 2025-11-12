#include <bits/stdc++.h>
using namespace std;
int a,len=1,m,n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int all=n*m;
	cin>>a;
	int tmp;
	for(int i=2;i<=all;i++)
	{
		cin>>tmp;
		if(tmp>a)len++;
	}
	int r=(len+n-1)/n;
	int c=(r%2==1)?(len%n):(n-(len%n)+1)%n;
	printf("%d %d",r,(c==0)?n:c);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//9:30Íê³É 
