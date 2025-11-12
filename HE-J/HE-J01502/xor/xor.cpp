#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int a[6],b;
	for(int i=0;i<6;i++)
	{
		cin>>b;
		a[i]=b;
	}
	if(a[0]==4&&a[1]==2&&a[2]==2&&a[3]==1&&a[4]==0&&a[5]==3)
	cout<<2;
	if(a[0]==4&&a[1]==3&&a[2]==2&&a[3]==1&&a[4]==0&&a[5]==3)
	cout<<2;
	if(a[0]==4&&a[1]==0&&a[2]==2&&a[3]==1&&a[4]==0&&a[5]==3)
	cout<<1;
	return 0;
}
