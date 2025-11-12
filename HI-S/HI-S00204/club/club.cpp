#include<bits/stdc++.h>
using namespace std;
int n,a[100010][3],q,ma[100010],num;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q>>n;
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];sssssss
			ma[i]=a[i][1];
			if(a[i][2]==0&&a[i][3]==0)
			{
				sort(ma+1,ma+n+1,cmp);
				
			}
		}
		for(int i=1;i<=n/2;i++)
			num+=ma[i];
		cout<<num<<endl;
	}
	return 0;
 } 
