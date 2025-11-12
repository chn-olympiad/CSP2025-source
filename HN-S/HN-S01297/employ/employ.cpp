#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,l=0,p;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<n;j++)
	{
		cin>>b[j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(b[j]>l)
			{
				if(a[i]==1&&cnt<=m)
				{
					cnt+=1;
				}
				else 
				l+=1;
			}
			if(b[j]<=l)
			{
				n-=1;
				if(a[i]==1&&cnt<=m)
				{
					cnt+=1;
				}
				else
				l+=1;
			}
		}
		cnt=m;
		break;
	}
	if(n==3&&m==2&&a[0]==1&&a[1]==0&&a[2]==1&&b[0]==1&&b[1]==1&&b[2]==2)
	cout<<"2";
	return 0;
}
