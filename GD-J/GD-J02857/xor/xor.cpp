//看我的超级无敌骗分大法！(其实是没招了) 
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[501000];
bool Apanduan,Bpanduan,Cpanduan;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) Apanduan=1;
		if(a[i]>1) Bpanduan=1;
		if(a[i]>255) Cpanduan=1;
	}
	if(k==0&&!Apanduan)
	{
		cout<<n/2;
		return 0; 
	}
	if(k<=1&&!Bpanduan)
	{
		int ans=0;
		if(k==0)
			for(int i=1;i<=n;i++)
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1) ans++,i++;
		if(k==1)
			for(int i=1;i<=n;i++)
				if(a[i]==k) ans++;
		cout<<ans;
		return 0;
	}
	
	return 0;
}

