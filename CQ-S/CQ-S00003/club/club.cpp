#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt=0,q[5005];
struct node
{
	int x,y,z;
}a[50005];	
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
		for(int j=1;j<=q[i];j++)
		{
			cin>>a[cnt*q[i]+j].x>>a[cnt*q[i]+j].y>>a[cnt*q[i]+j].z;
		}
		cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		int w=0;
		w++;
		for(int j=1;j<=q[i];j++)
		{
	 		ans+=max(a[cnt*q[i]+j].x,a[cnt*q[i]+j].y,a[cnt*q[i]+j].z);
	 	}
	 	if(w==q[i])
		{
			cout<<ans<<endl;
			ans=0;
			w=0;
		}
	}
	return 0;
}
