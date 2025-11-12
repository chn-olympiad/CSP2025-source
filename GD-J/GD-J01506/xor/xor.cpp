#include<bits/stdc++.h>
using namespace std;
long long que_[500010];
bool cmp(int a,int b)
{
	return a<b;
}
int qzh[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>qzh[i];
	}
	int m=0;
	for(int i=1;i<=n;i++)
	{
		int yh=0;
		for(int j=i;j<=n;j++)
		{
			yh=yh^qzh[j];
			if(yh==k)
			{
				m++;
				que_[m]=i*1000000+j;
				break;
			}
		}
	}
	sort(que_+1,que_+m+1,cmp);
	int ans=0,lastr=0;
	for(int i=1;i<=m;i++)
	{
		int ql=que_[i]/1000000;
		int qr=que_[i]%1000000;
		if(lastr<ql)
		{
			ans++;
			lastr=qr;
		}
	}
	cout<<ans;
	return 0; 
}
