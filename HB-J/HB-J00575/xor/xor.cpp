#include<bits/stdc++.h>
using namespace std;
long long a[1010],t[1010],b[1010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x=0,y=0;
		while(a[i])
		{
			x+=a[i]%2*pow(10,y);
			a[i]/=2;
			y++;
		}
		t[i]=x;
	}
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=i;j<=n;j++)
		{
			s+=t[j];
			int f=s,g=0;
			while(f)
			{
				g+=f%2;
				f/=2;
			}
			if(g==k&&j-i+1!=n&&b[i]==0&&b[j]==0)
			{
				num++,cout<<g<<" "<<i<<" "<<j<<endl;
				for(int k=i;k<=j;k++)
					b[k]=1;
			}
		}
	}
	cout<<num;
	return 0;
}
