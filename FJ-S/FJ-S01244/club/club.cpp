#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int a[N][3];
int ans[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int te=0;//存ans数组的编号 
	while(t--)
	{
		int sum=0;
		int cgsl=0;
		int n;
		int zdbh[5]={0};//每个编号出现次数
		int zgzdbh[N]={0};//当前数的最大值的编号
		int zgzdz[N]={0};//这个数的最大值
		int h[N]={0};
		cin>>n;
		int man=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxn=a[i][1];
			int maxsh=1;
			if(a[i][2]>maxn)
			{
				maxn=a[i][2];
				maxsh=2;
			}
			if(maxn<a[i][3])
			{
				maxn=a[i][3];
				maxsh=3;
			}
			zdbh[maxsh]++;
			zgzdbh[i]=maxsh;
			sum+=maxn;
			zgzdz[i]=maxn;
		}
		int l=0;
		for(int i=1;i<=3;i++)
		{
			if(zdbh[i]>man)
			{
				cgsl=zdbh[i]-man;
				l=i;
				break;
			}
		}
		te++;
		if(!l)
		{
			ans[te]=sum;
			continue;
		}
		int mj=0;
		for(int i=1;i<=n;i++)
		{
			int count=0;
			if(zgzdbh[i]==l)
			{
				mj++;
				for(int j=1;j<=3;j++)
				{
					if(j==l)
					{
						continue;
					}
					else{
						count=max(count,a[i][j]);
					}
				}
				h[mj]=zgzdz[i]-count;
			}
		}
		sort(h+1,h+1+mj);
		for(int i=1;i<=cgsl;i++)
		{
			sum=sum-h[i];
		}
		ans[te]=sum;
	}
	for(int i=1;i<=te;i++) cout<<ans[i]<<"\n";
	return 0;
} 
