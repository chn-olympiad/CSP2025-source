#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ok=1,ok1=1,ok2=1;
long long b[500005];//前缀和
int rp[500005];//编号j-数值==k时最小 
bool hi[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(!(a[i]==1))
		{
			ok=0;
		}
		if(!(a[i]==1||a[i]==0))
		{
			ok1=0;
		}
		if(!(a[i]<=255))
		{
			ok2=0;
		}
	}
	if(ok)
	{
		cout<<n/2;
		return 0;
	}
	else if(ok1)
	{
		if(k==0)
		{
			int t=0;
			for(int i=1; i<=n; i++)
			{
				if((a[i]==1&&i+1<=n&&a[i+1]==1&&!(hi[i])&&!(hi[i+1]))||(a[i]==0))
				{
					hi[i]=1;
					hi[i+1]=1;
					t++;
				}
			}
			cout<<t;
		}
		if(k==1)
		{
			int t=0;
			for(int i=1; i<=n; i++)
			{
				if(a[i]==1)
				{
					t++;
				}
			}
			cout<<t;
		}
	}
	else
	{
		b[1]=a[1];
		rp[1]=-1;
		for(int i=2; i<=n; i++)
		{
			b[i]=b[i-1]^a[i];
			rp[i]=-1;
		}
//		for(int i=1; i<=n; i++) cout<<b[i]<<" ";
//		cout<<endl;
		for(int j=1; j<=n; j++)
		{
			for(int i=j; i>=1; i--)
			{
				long long ss=b[j]^b[i-1];
				if(i==j) ss=a[i];
				if(i==1) ss=b[j];
				if(ss==k)
				{
//					cout<<"j< "<<j<<"i< "<<i<<"a[j]< "<<a[j]<<"a[i]< "<<a[i]<<"sum:"<<ss<<endl;
					rp[j]=i;
					break; 
				}
			}
		}
//		for(int i=1; i<=n; i++) cout<<rp[i]<<" ";
//		cout<<endl;
		int beforej=1,ans=0;
		for(int i=1;i<=n;i++)
		{
	//		if(rp[i]>=beforej)		
			if(rp[i]>=beforej&&rp[i]!=-1)
			{
//				cout<<i<<" "<<endl; 
				ans++;
				beforej=i+1;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
