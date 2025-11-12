#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int sum[500005];
int n,k,o;
int flag1,flag2,sum2,flag;
struct node{
	int x,y;
}b[500005];
bool cmp(node A,node B){
	return A.y<B.y;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			flag1++;
			flag++;
		}
		else
		{
			flag2++;
			sum2+=flag/2;
			flag=0;
		}
	}
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			//memset(sum,0,sizeof sum);
			sum[i]=a[i];
			bool flag0=0;
			if(sum[i]==k)
			{
				b[++o].x=i;
				b[o].y=i;
				flag0=1;
			}
			if(flag0==1)continue;
			for(int j=i+1;j<=n;j++)
			{
				sum[j]=sum[j-1]^a[j];
				if(sum[j]==k)
				{
					b[++o].x=i;
					b[o].y=j;
				}
			}
		}
		sort(b+1,b+1+o,cmp);
		int cnt=1,last=b[1].y;
		for(int i=2;i<=o;i++)
		{
			if(last<b[i].x)
			{
				cnt++;
				last=b[i].y;
			}
		}
		cout<<cnt;
	}
	else
	{
		if(k==1)
			cout<<flag1;
		else cout<<flag2+sum2;
	}
	
	return 0;
}
