#include<bits/stdc++.h>
using namespace std;
int n,k,X,ans;
int a[500020];
bool b[500020];
bool flag1=1,flag2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			flag1=0;
		if(a[i]!=1&&a[i]!=0)
			flag2=0;
	}
	if(flag1)
	{
		if(k==1)
			cout<<n;
		if(k==0)
			cout<<n/2;
		return 0;
	}
	if(flag2)
	{
		if(k==1)
			for(int i=1;i<=n;i++)
				if(a[i]==1&&((a[i-1]==0&&!b[i-1]&&i-1>=1)||(a[i+1]==0&&!b[i+1]&&i+1<=n)))
				{
					if(a[i-1]==0&&!b[i-1])
						b[i-1]=1;
					else if(a[i+1]==0&&!b[i+1])
						b[i+1]=1;
					ans++;
				}
		if(k==0)
		{
			for(int i=2;i<=n;i++)
				if(a[i]==a[i-1]&&!b[i-1])
				{
					b[i]=1;
					ans++;
				}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		X=X^a[i];
		if(X==k)
		{
			X=0;
			ans++;
		}
	}
	cout<<ans;
} 
