#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	 for(int i=1;i<=n;i++)
	     for(int j=i+1;j<=n;j++)
	         for(int k=j+1;k<=n;k++)
	             {
	             	if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k]))) ans++;
				 }
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
