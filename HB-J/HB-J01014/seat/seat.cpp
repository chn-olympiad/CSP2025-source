#include<bits/stdc++.h>
using namespace std;
int n,m,nm,j=0,Rsc=0,t=1,x=1,y=1;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(int i=1;i<=nm;i++)
		scanf("%d",&a[i]);
	Rsc=a[1];
	sort(a+1,a+nm+1,greater<int> ());
	for(int i=1;i<=nm;i++)
	{
		if(a[i]==Rsc)
		{
			j=i;
			break;
		}
	}
	//cout << j << endl;
	while(t!=j)
	{
		while(x!=n && t!=j)
		{
			x++;
			t++;
		//	cout << "x:" << x << "    t:" << t << endl;
		}
		if(t!=j)
		{
			y++;
			t++;
		//	cout << "y:" << y << "    t:" << t << endl;
		}
		while(x!=1 && t!=j)
		{
			x--;
			t++;
		//	cout << "x:" << x << "    t:" << t << endl;
		}
		if(t!=j)
		{
			y++;
			t++;
		//	cout << "y:" << y << "    t:" << t << endl;
		}
	//	cout << "------------------------------" << endl << endl;
	}
	printf("%d %d",y,x);
	return 0;
}
