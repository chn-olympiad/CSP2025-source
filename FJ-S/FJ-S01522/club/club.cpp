#include<bits/stdc++.h>
using namespace std;
struct nnn
{
	int x,y,z,fi; 
}a[1000005];
bool cmp1(nnn aa,nnn bb)
{
	return (aa.x-aa.y<bb.x-bb.y)||(aa.x-aa.z<bb.x-bb.z);
}
bool cmp2(nnn aa,nnn bb)
{
	return aa.y-aa.z>bb.y-bb.z;
}
bool cmp3(nnn aa,nnn bb)
{
	return aa.x>bb.x;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,tot1=0,tot2=0,tot3=0,ans=0,f1=1;
		cin>>n;
		int mx=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0&&a[i].z!=0)f1=0;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)a[i].fi=1;
			else if(a[i].y>=a[i].z)a[i].fi=2;
			else a[i].fi=3;
		}
		if(f1)
		{
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans;
			continue;
		}
	    for(int i=1;i<=n;i++)
	    {
	    	if(a[i].fi==1)tot1++;
	    	if(a[i].fi==2)tot2++;
	    	if(a[i].fi==3)tot3++;
	    }
	    //cout<<tot1<<' '<<tot2<<' '<<tot3<<'\n';
	    //cout<<"ddd";
	    if(tot1>mx)
	    {
	    	sort(a+1,a+1+n,cmp1); 
	    	for(int i=1;i<=tot1-mx;i++)
	    	{
	    		if(a[i].y>=a[i].z)a[i].fi=2;
	    		else a[i].fi=3;
			}	
		}
		if(tot2>mx)
		{
			sort(a+1,a+1+n,cmp2); 
	    	for(int i=1;i<=tot2-mx;i++)
	    	{
	    		a[i].fi=3;
			}
		}
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i].fi<<'\n';
			if(a[i].fi==1)ans+=a[i].x;
			if(a[i].fi==2)ans+=a[i].y;
			if(a[i].fi==3)ans+=a[i].z;
		}
		cout<<ans<<'\n';
    }
	return 0;
}
