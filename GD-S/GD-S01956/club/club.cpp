#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],a1[100005],b1[100005],c1[100005];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	 
	cin>>T;
	while(T--)
	{
		cin>>n;
		int aa=0,bb=0,cc=0;
		long long ans=0;
		for(int i=0;i<=100001;i++)
		{
			a[i]=b[i]=c[i]=a1[i]=b1[i]=c1[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) ans+=a[i],aa++,a1[a[i]-max(b[i],c[i])]++;
			if(b[i]>a[i]&&b[i]>=c[i]) ans+=b[i],bb++,b1[b[i]-max(a[i],c[i])]++;
			if(c[i]>a[i]&&c[i]>b[i]) ans+=c[i],cc++,c1[c[i]-max(b[i],a[i])]++;
		}
		if(aa>n/2)
		{
			int x=aa-n/2;
			for(int i=0;;i++)
			{
				if(a1[i])
				{
					ans=ans-min(x,a1[i])*i;
					x-=a1[i];
				}
				if(x<=0){
					break;
				}
				
			}
		}
		if(bb>n/2)
		{
			int x=bb-n/2;
			for(int i=0;;i++)
			{
				if(b1[i])
				{
					ans=ans-min(x,b1[i])*i;
					x-=b1[i];
				}
				if(x<=0){
					break;
				}
				
			}
		}
		if(cc>n/2)
		{
			int x=cc-n/2;
			for(int i=0;;i++)
			{
				if(c1[i])
				{
					ans=ans-min(x,c1[i])*i;
					x-=c1[i];
				}
				if(x<=0){
					break;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	

	
	return 0;
} 
