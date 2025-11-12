#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],x,y,b[100005],t,p=0;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--)
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])x++;
		else if(a[i][1]<a[i][2]&&a[i][2]>=a[i][3])y++;
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i][2]==a[i][3]&&a[i][2]==0);
		else p=1;
	}
	if(p==0)
	{
		for(int i=1; i<=n; i++)
			b[i]=a[i][1];
		sort(b+1,b+n+1);
		for(int i=n; i>n/2; i--)
			ans+=b[i];
	}
	else{
		p=0;
		for(int i=1; i<=n; i++)
			if(a[i][3]==a[i-1][3]&&a[i][3]==0);
			else p=1;
		if(p==0)
		{
			for(int i=1; i<=n; i++)
				ans+=a[i][1],b[i]=a[i][2]-a[i][1];
			sort(b+1,b+n+1);
			for(int i=n; i>n/2; i--)
				ans+=b[i];
		}
	else 
	{	
	for(int i=1; i<=n; i++)
		ans+=max(a[i][1],max(a[i][2],a[i][3]));
	if(x<=n/2&&y<=n/2&&n-x-y<=n/2);
	else 
	{
		if(x>n/2)
		{
			for(int i=1; i<=n; i++)
				b[i]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
			sort(b+1,b+n+1);
			for(int i=n; i>n-(x-n/2); i--)
				ans+=b[i]; 
		}
		else if(y>n/2)
		{ 
			for(int i=1; i<=n; i++)
				b[i]=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
			sort(b+1,b+n+1);
			for(int i=n; i>n-(y-n/2); i--)
				ans+=b[i]; 
		}
		else if(n-x-y>n/2){
			for(int i=1; i<=n; i++)
				b[i]=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
			sort(b+1,b+n+1);
			for(int i=n; i>n-(n-x-y-n/2); i--)
				ans+=b[i]; 
		}
	}
	}
}
	cout<<ans<<"\n";
	ans=0,x=0,y=0;
	for(int i=1; i<=n; i++)b[i]=0;

}
	return 0;
}
