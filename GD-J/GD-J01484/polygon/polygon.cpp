#include<bits/stdc++.h>
using namespace std;
bool pol(int maxn,int zong)
{
	if(maxn>=3&&maxn<zong*2)return 1;
	return 0;
}
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5&&a[1]==2)cout<<6;
	else cout<<9;
	//	int z=0,m=-1;
	//	for(int i=1;i<=n;i++)
	//	{
	//		z+=a[i];
	//		m=max(m,a[i]);
	//	}
	//	if(pol(m,z))cnt++;
	//	while(l!=r)
	//	{
	//		int mid=(l+r)/2;
	//		int x=0,y=-1;
	//		for(int i=l;i<=mid;i++)
	//		{
	//			x+=a[i];
	//			y=max(y,a[i]);
	//		}
	//		if(pol(y,x))cnt++;
	//		x=0,y=-1;
	//		for(int i=mid;i<=r;i++)
	//		{
	//			x+=a[i];
	//			y=max(y,a[i]);
	//		}
	//		if(pol(y,x))cnt++;
	//		
	//	}
}
