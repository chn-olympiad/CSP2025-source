#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[5000];
void hx(int s,int no,int nu)
{
	if(nu==1)
	{
		for(int i=no+1;i<n;i++)
			if(a[i]<s)
				ans++;
		return;
	}
	for(int i=no+1;i<=n-nu;i++)
		hx(s+a[i],i,nu-1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		for(int j=2;j<n-i;j++)
			hx(a[i],i,j);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
