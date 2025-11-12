//GZ-S00378遵义市南白中学胡丞棋 
#include<bits/stdc++.h>
using namespace std;
int max3(int a,int b,int c)
{
	if(a>b&&a>c) return a;
	if(b>a&&b>c) return b;
	if(c>a&&c>b) return c;
}
int which_max(int a,int b,int c)
{
	if(a>b&&a>c) return 0;
	if(b>a&&b>c) return 1;
	if(c>a&&c>b) return 2;
}
bool ifavaliable(int all,int a,int b,int c)
{
	if(a<=all/2&&b<=all/2&&c<=all/2) return true;
	else return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int group;
	cin>>group;
	for(int i=1;i<=group;i++)
	{
		int n,club_num[3];
		cin>>n;
		int a[n][3];
		for(int j=0;j<n;j++)
		{
			cin>>a[j][0];
			cin>>a[j][1];
			cin>>a[j][2];
		}
		int best=0;
		for(int j=0;j<n;j++)
		{
			best+=max3(a[j][0],a[j][1],a[j][2]);
		}
		cout<<best;
	}
	return 0;
}

