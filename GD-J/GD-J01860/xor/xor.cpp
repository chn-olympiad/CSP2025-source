#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,q,ma,qq,qqq,yb;
string st;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		 scanf("%lld",&a[i]);
		 if(a[i]==0) q++;
		 else if(a[i]==1) qq++; 
		 if(a[i]==1&&a[i-1]==1) qqq++;
		 else 
		 if(a[i]==0&&a[i-1]==1)
		 {
		 	ans+=(qq/2);
		 	if(qq%2==1) ans++;
		 	qq=0;
		 }
		 ma=max(ma,a[i]);
		 if(k!=0&&k!=1&&a[i]==k) yb++;
	}
	if(n==2)
	{
		if((a[1]^a[2])==k) ans++;
		if(a[1]==k&&a[2]==k) ans=2;
		cout<<ans;
	}
	else
	if(ma==1) 
	{
		if(k==1) cout<<qq;
		else cout<<q+qqq;
	}
	else cout<<yb;
	return 0;
 } 
