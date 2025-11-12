#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],ans=0,b,c,lon=0;
bool flag=1;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i];	
	if(a[i]!=1)flag=0;
}
sort(a+1,a+n+1);
if(n<=3)
{
	b=a[1]+a[2]+a[3];
	c=max(max(a[1],a[2]),a[3]);
	if(b>c*2) cout<<"1";
	else cout<<"0";
} else {
	if(flag){
		ans=n*(n-1)*(n-2)*(n-3)/4-1;
		cout<<ans;
		return 0;
	} else {
		for(int l=1;l<=n-2;l++)
			for(int r=l+2;r<=n;r++)
			{
				lon=0;
				for(int i=l;i<=r;i++)
				{
					lon=lon+a[i];
					if(lon>a[i]*2) ans++;
				}	
			}
		cout<<ans;
	}
}
return 0;
}
/*
5
1 2 3 4 5
*/
