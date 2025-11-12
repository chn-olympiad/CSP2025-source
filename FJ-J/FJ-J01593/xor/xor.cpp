#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k,a[N],num,cnt1,cnt0;
bool flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];	
		if(a[i]==0)
			flag=true,cnt0++;
		if(a[i]==1)
			cnt1++;
	}
	if(!flag&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<n;++i)
			if(a[i]^a[i+1]==1)
				num++,++i;
		cout<<max(cnt1,num);
		return 0;
	}
	if(k==0)	
	{
		for(int i=1;i<n;++i)
			if(a[i]^a[i+1]==0)
				num++,++i;
		cout<<max(cnt0,num);
		return 0;
	}		
	return 0;
}
