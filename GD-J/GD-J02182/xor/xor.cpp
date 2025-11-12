#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,k;
long long a[N],ans;
bool fl=true,ag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)fl=false;
		if(a[i]>1)ag=false;
	}
	if(fl)
	{
		cout<<n/2;
		return 0;
	}
	if(ag)
	{
		if(k==1)
		{
			for(int i=0,j=1;i<n&&j<n;i++,j++)
			{
				if(a[i]+a[j]==1)
				{
					ans++;
					i++,j++;
				}
			}
		}
		else
		{
			for(int i=0,j=1;i<n&&j<n;i++,j++)
			{
				if(a[i]+a[j]==0||a[i]+a[j]==2)
				{
					ans++;
					i++,j++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
