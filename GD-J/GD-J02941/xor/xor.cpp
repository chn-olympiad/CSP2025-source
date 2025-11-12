#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],x[1000005],f[1005][1005],k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	cin>>n>>k;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		//cout<<x[i]<<" ";
	}
	//cout<<endl;
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n-i;j++)
			{
				int num=0;
				if(j==0)
				{
					if(a[i]==k)num=1;
					f[1][i+j]=max(f[1][i-1]+num,f[1][i+j]);
					//cout<<1<<":"<<i+j<<"="<<f[1][i+j]<<" "<<"num"<<"="<<num<<endl;
					continue;
				}
				int num1=x[i-1]^x[i+j];
				if(num1==k)
				{
					//cout<<x[i-1]<<"^"<<x[i+j]<<"=";
					//cout<<num1<<endl;
					num=1;
				}
				f[1][i+j]=max(f[1][i-1]+num,f[1][i+j]);
				//cout<<1<<":"<<i+j<<"="<<f[1][i+j]<<" "<<"num"<<"="<<num<<endl;
			}
		}
		
		cout<<f[1][n]<<endl;
	}
	return 0;
 }
