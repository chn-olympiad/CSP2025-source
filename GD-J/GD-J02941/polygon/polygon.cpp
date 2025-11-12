#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,a[5005],num[5005],t,r[5005],ans;
bool check[5005],check1=true;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","polygon.in",stdin);
	freopen("w","polygon.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!check[a[i]])
		{
			check[a[i]]=true;
			r[t]=a[i];
			t++;
		}
		if(a[i]!=1)
			check1=false;
		num[a[i]]++;
	}
	sort(r,r+t);
	int l=1;
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			l*=2;
		}
		l-=1;
		for(int i=1;i<=l;i++)
		{
			int num2=i,sum1=0,maxn=0,num3=0;
			int ti=1;
			while(num2>0)
			{
				if(num2%2==1)
				{
					sum1+=a[ti];
					maxn=max(maxn,a[ti]);
					//cout<<a[ti]<<" ";
					num3++;
				}
				num2/=2;
				ti++;

			}
			if(sum1>maxn*2&&num3>=3)
			{
				//cout<<"true";
				ans++;
			}
			//cout<<endl;
		}
	}
	else if(check)
	{
		int l3=1;
		for(int i=1;i<=n;i++)
		{
			l3*=2;
			l3%=MOD;
		}
		l3--;
		l3-=n;
		l3-=(n*(n-1))/2;
		ans=l3;
	}
	cout<<ans<<endl;
	return 0;
 }
