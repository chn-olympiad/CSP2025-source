#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],m[500010];
bool b1=true,b2=true;
long long cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int kl=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==k) kl++;
		if(a[i]!=1) b1=false;
		if(!(a[i]==0||a[i]==1)) b2=false;
	}
	if(b1&&b2)
	{
		cout<<max(n/2,kl);
		return 0; 
	}
	if(b1)
	{
		cout<<n/2;
		return 0;
	}
	if(b2)
	{
		cout<<kl;
		return 0;
	}
	for(int i=1;i<=n;i++) a[i]=a[i]^a[i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int res=1,r=a[i-1]^a[j],s=a[i-1]^a[i];
			//cout<<"i"<<i<<":"<<a[i]<<" j"<<j<<":"<<a[j]<<" "<<cnt;
			if(r==k||(i==j&&s==k))
			{
				//cout<<"\n";
				for(int l=i;l<=j;l++)
					if(m[l]!=0) res=0;
				//cout<<res<<"[";
				m[i]+=res;
				m[j+1]-=res;
				if(res==1) for(int l=1;l<=n;l++) m[l]=m[l-1]+m[l];
				//if(res==1) for(int l=1;l<=n;l++) cout<<m[l]<<",";
				cnt=cnt+res;
				//cout<<"]***";
			}
			//cout<<"\n";
		}
	}
	cout<<cnt;
	return 0;
} 
