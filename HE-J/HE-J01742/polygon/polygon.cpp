#include<bits/stdc++.h>
using namespace std;
int main()
{
	preopen("polygon.in","r",stdin);
	preopen("polygon.in","w",stdout);
	int a,b,c,d,ans=0;
	cin >>a>>b>>c>>d;
	if (b+a>c && b+c>a && a+c>b)
		cout <<1;
	else
		cout <<0;
}
