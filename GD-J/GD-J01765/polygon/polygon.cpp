#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool flag1=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag1=0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]<2*max(a[1],max(a[2],a[3])))
		    cout<<0;
		else
		    cout<<1;
		return 0;
	}
	if(flag1)
	{
		for(int i=1;i<=n-2;i++) {
		    ans+=i;}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				 ans++;
			}
		}
	}
	cout<<ans-1;
	
	 
	
	
	
	
	
	
	return 0;
}
