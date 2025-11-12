#include<bits/stdc++.h>
using namespace std;
long a[200000];
bool cmp[200000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long n,k,sum,ans=0;
	cin>>n,k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum=(sum^a[i]);
		for(int j=2;j<=n;j++)
		{
		    if(sum==k||a[j]==k&&cmp[j]==true){
		    	ans++;
		    	for(int m=i;m<=j;m++) cmp[m]=false;
			} 
			sum=(sum^a[j]);	
		}
	    sum=(sum^a[i]);
	}
	cout<<ans;
}
