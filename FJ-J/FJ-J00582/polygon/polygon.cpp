#include<bits/stdc++.h>
using namespace std;
int a[5021];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n==3)
	{
		int maxx=max(a[0],a[1]);
		maxx=max(maxx,a[2]);
		if((a[0]+a[1]+a[2])>2*maxx)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else if(n==4)
	{
		int s=0;
		int maxx=max(max(a[0],a[1]),a[2]);
		if((a[0]+a[1]+a[2])>2*maxx)
			s++;
		maxx=max(max(a[0],a[1]),a[3]);
		if(a[0]+a[1]+a[3]>2*maxx)
			s++;
		maxx=max(max(a[0],a[2]),a[3]);
		if(a[0]+a[2]+a[3]>2*maxx)
			s++;
		maxx=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>2*maxx)
			s++;
		maxx=max(max(a[0],a[1]),max(a[2],a[3]));
		if((a[0]+a[1]+a[2]+a[3])>2*maxx)
			s++;
		cout << s;
	}
	else
	{
		int s=0;
		int maxx=max(max(a[0],a[1]),a[2]);
		if((a[0]+a[1]+a[2])>2*maxx)
			s++;
		maxx=max(max(a[0],a[1]),a[3]);
		if(a[0]+a[1]+a[3]>2*maxx)
			s++;
		maxx=max((a[0],a[1]),a[4]);
		if(a[0]+a[1]+a[4]>2*maxx)
			s++;
		maxx=max(max(a[0],a[2]),a[3]);
		if(a[0]+a[2]+a[3]>2*maxx)
			s++;
		maxx=max(max(a[0],a[2]),a[4]);
		if(a[0]+a[2]+a[4]>2*maxx)
			s++;
		maxx=max(max(a[0],a[3]),a[4]);
		if(a[0]+a[3]+a[4]>2*maxx)
			s++;
		maxx=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>2*maxx)
			s++;
		maxx=max(max(a[1],a[2]),a[4]);
		if(a[1]+a[2]+a[4]>2*maxx)
			s++;
		maxx=max(max(a[1],a[3]),a[4]);
		if(a[1]+a[3]+a[4]>2*maxx)
			s++;
		maxx=max(max(a[2],a[3]),a[4]);
		if(a[2]+a[3]+a[4]>2*maxx)
			s++;
		maxx=max(max(a[0],a[1]),max(a[2],a[3]));
		if((a[0]+a[1]+a[2]+a[3])>2*maxx)
			s++;
		maxx=max(max(a[0],a[1]),max(a[2],a[4]));
		if((a[0]+a[1]+a[2]+a[4])>2*maxx)
			s++;
		maxx=max(max(a[0],a[1]),max(a[3],a[4]));
		if((a[0]+a[1]+a[3]+a[4])>2*maxx)
			s++;
		maxx=max(max(a[0],a[2]),max(a[3],a[4]));
		if((a[0]+a[2]+a[3]+a[4])>2*maxx)
			s++;
		maxx=max(max(a[1],a[2]),max(a[3],a[4]));
		if((a[1]+a[2]+a[3]+a[4])>2*maxx)
			s++;
		maxx=max(max(max(a[0],a[1]),(a[2],a[3])),a[4]);
		if((a[0]+a[1]+a[2]+a[3]+a[4])>2*maxx)
			s++;
		cout << s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
