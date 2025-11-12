#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],k,c,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i]==k) 
		{
			c=i;
			break;
		}
	}
//	while(c>=n) {
//		c-=n,ans1++;
//	}
	ans1=c/n,ans2=c-ans1*n;
	if(ans1%2==0) 
	{
		if(c%n==0) ans1=c/n;
		else ans1=c/n+1;
		if(ans2==0) ans2=1;
		cout<<ans1<<" "<<ans2;
	}
	else 
	{
		if(c%n==0) ans1=c/n;
		else ans1=c/n+1;
		if(ans2==0) cout<<ans1<<" "<<n;
		else cout<<ans1<<" "<<n-ans2+1;
	}
	return 0;
}
