#include<bits/stdc++.h>
using namespace std;
int a,b[50004],l,c[10];
void bobobo(int x,int y,int z,int s)
{
	if(x>2*y && z>=3)
	{
		l++;
		if(s>a)return;
	}
	for(int i=s;i<=a;i++)
	{
		bobobo(x+b[i],max(b[i],y),z+1,i+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)cin>>b[i];
	bobobo(0,INT_MIN,0,1);
	cout<<l;
	return 0;
}
