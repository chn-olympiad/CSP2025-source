#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y,z;
}a[100005];
bool bmp(node w,node v)
{
	return w.x>v.x;
}
bool b[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		bool bo=false;
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x*a[i].y*a[i].z!=0) bo=true;
		}
		if(bo==false)
		{
			sort(a+1,a+1+n,bmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
		}	
		cout<<ans<<" "<<0<<" "<<0<<" "<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
return 0;
}
