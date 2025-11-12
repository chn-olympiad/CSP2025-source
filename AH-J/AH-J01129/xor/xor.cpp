#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
long long sum;
long long a[N];
long long f[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
		   f[i]=a[i];
		}
		else
		{
			f[i]=f[i-1]^a[i];
		}
	}
	for(int i=1,j,last=0;i<=n;i++)
	{
		for(j=last;j<i;j++)
		{
			long long tmp=f[j]^f[i];
			if(tmp==k)
			{	
			   last=i;	   
			   sum++;
			   break;
			}
			
		}
	}
	cout<<sum;
	return 0;
}
