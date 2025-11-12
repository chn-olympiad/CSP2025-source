#include<bits/stdc++.h>
using namespace std;

int a[100002][12];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)
	{
		int n,zo,o=0;
		cin>>n;
		zo=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][4]=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		if(n==1)
		{
			o=a[1][4];
		}
		if(n==2)
		{
			o=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			o=max(o,a[1][2]+a[2][1]);
			o=max(o,a[1][2]+a[2][3]);
			o=max(o,a[1][3]+a[2][1]);
			o=max(o,a[1][3]+a[2][2]);
		}
		else if(n==3)
		{
			o=max(a[1][1]+a[2][2]+a[3][3],a[1][1]+a[3][2]+a[2][3]);
			o=max(o,a[2][1]+a[1][2]+a[3][3]);
			o=max(o,a[2][1]+a[3][2]+a[1][3]);
			o=max(o,a[3][1]+a[1][2]+a[2][3]);
			o=max(o,a[3][1]+a[2][2]+a[1][3]);
		}
		else if(n==4)
		{
			o=max(a[1][1]+a[2][1]+a[3][2]+a[4][2],a[1][1]+a[2][1]+a[3][2]+a[4][3]);
			o=max(o,a[1][1]+a[2][1]+a[3][3]+a[4][3]);
			o=max(o,a[1][1]+a[2][1]+a[3][3]+a[4][2]);
			o=max(o,a[1][1]+a[2][1]+a[3][3]+a[4][1]);
			o=max(o,a[1][1]+a[2][2]+a[3][1]+a[4][2]);
			o=max(o,a[1][1]+a[2][2]+a[3][1]+a[4][3]);
			o=max(o,a[1][1]+a[2][2]+a[3][3]+a[4][3]);
			o=max(o,a[1][1]+a[2][2]+a[3][3]+a[4][1]);
			o=max(o,a[1][1]+a[2][3]+a[3][1]+a[4][2]);
			o=max(o,a[1][1]+a[2][3]+a[3][2]+a[4][2]);
			o=max(o,a[1][1]+a[2][3]+a[3][3]+a[4][2]);
			o=max(o,a[1][1]+a[2][3]+a[3][1]+a[4][3]);
			o=max(o,a[1][1]+a[2][3]+a[3][3]+a[4][1]);
			o=max(o,a[1][1]+a[2][3]+a[3][2]+a[4][1]);
		}
		else if(a[1][2]==a[1][3]&&a[1][3]==0)
		{
			int aaa[100002];
			for(int i=1;i<=n;i++)
			{
				aaa[i]=a[i][1];
			} 
			sort(aaa+1,aaa+n+1);
			for(int i=n;i>=n-zo+1;i--)
			{
				o+=aaa[i]; 
			}
		}
		cout<<o;
	}
	return 0;
}

/*
2
6
1 6 0
2 5 0
3 4 0
4 3 0
5 2 0
6 1 0


*/



















