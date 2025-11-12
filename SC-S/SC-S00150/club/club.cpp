#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,mx,p1=0,p2=0,p3=0,ans=0,ll[6];
int main(){
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1>>a2>>a3;
			mx=max(a1,max(a2,a3));
			if(mx==a1&&p1+1<=n/2)
			{
				p1++;
				ans=ans+a1;
			}
			if(mx==a2&&p2+1<=n/2)
			{
				p2++;
				ans=ans+a2;
			}
			if(mx==a3&&p3+1<=n/2)
			{
				p3++;
				ans=ans+a3;
			}
		}
		ll[z]=ans;
		ans=0;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ll[i]<<endl;
	}
	return 0;
}

