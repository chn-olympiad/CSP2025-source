#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b;
	d=1;
	cin>>c;
	for(int i=1;i<a*b;i++)
	{cin>>e;
	if(e>c)
	d=d+1;
	}
	cout<<d<<endl;
	e=0;
	e=d%a;
	cout<<e<<endl;
	f=d/a;
	cout<<f<<endl;
	if(e!=0)
	f++;
	if(e==0)
	e=a;
	if(f%2==0)
	e=a-e+1;
	cout<<f<<" "<<e;
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
