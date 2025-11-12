#include<bits/stdc++.h>
using namespace std;

int n,m,a[10086],aa,pos,x,y;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	aa=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==aa)
		{
			pos=i;
			break;
		}
	}
	pos=n*m-pos;
	x=(pos)/n+1;
	int tmp=pos%(2*n);
	y=(tmp<n?(tmp+1):(2*n-tmp));
	
	cout<<x<<" "<<y;
	
	return 0;
}
/*

*****************************************************************************************
********************************
*****************************************************
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                                        *****   *****   *****   ******  *****
                                        *       *    *  *    *  *    *  *    *
                                        *****   *****   *****   *    *  *****
                                        *       *   *   *   *   *    *  *   *
                                        *****   *    *  *    *  ******  *    *
*/ 
