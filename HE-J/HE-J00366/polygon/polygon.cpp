#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,ans=1;
	cin>>a;
	int c[a];
	for(int i=0;i<a;i++)
	{
		cin>>c[i];
	} 
	for(int i=1;i<=a;i++)
	{
		if(c[i]+c[i+1]>c[a])
		{
			ans++;
		}
		else if(c[i]+c[i+1]+c[i+2]>c[a])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
