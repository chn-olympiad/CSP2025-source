#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node
{
	int a[4];
	int b[4];
	int cho;
}a[100005];
int b[100005];
int tot;
int cnt[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=0;
		tot=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i= 1; i <= n; i++ )
		{
			for(int j= 1; j <= 3; j++ )
			{
				cin>>a[i].a[j];
				a[i].b[j]=a[i].a[j];
				
			}
			sort(a[i].b+1,a[i].b+4);
			sum+=a[i].b[3];
			for(int j = 1; j <= 3; j++ )
			{
				if(a[i].b[3]==a[i].a[j])
				{
//					cout<<" "<<j<<endl;
					a[i].cho=j;
					cnt[j]++;
					break;
				}
			}
		}
		int pp=0;
		for(int i = 1; i <= 3; i++ )
		{
			if(cnt[i]>(n/2))
			{
				pp=i;
			}
		}
//		cout<<pp<<" "<<cnt[pp]<<endl;
		if(pp==0)
		{
			cout<<sum<<endl;
			continue;
		}
		for(int i = 1; i <= n; i++ )
		{
			if(a[i].cho==pp)
			{
				tot++;
				b[tot]=a[i].b[3]-a[i].b[2];
			}
		}
//		cout<<tot<<" "<<cnt[pp]<<endl;
		sort(b+1,b+tot+1);
		for(int i= 1; i <= cnt[pp]-n/2;i++)
		{
//			cout<<b[i]<<endl;
			sum-=b[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0

*/ 
