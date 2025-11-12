#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,ans;
	cin>>a>>b;
	int z[a+1][b+1]={0};
	int c[100]={0};
	for(int i=0;i<a*b;i++)
	{
		cin>>c[i];
	}
	ans=c[0];
	for(int i=0;i<a*b;i++)
	{
	
		if(c[i]<c[i+1])
		{
			c[i]=c[i+1];
		}
		if(z[a][b]==ans)
		{
			cout<<a<<' '<<b;
			break;
		}
		else if(b+1>b)
		{
			z[a+1][b-1]=c[i];
		}
		else if(b-1<b)
		{
			z[a+1][b+1]=c[i];
		}
		else if(a+1>a)
		{
			z[a+1][b+1]=c[i];
		}
	}
	return 0;
}
