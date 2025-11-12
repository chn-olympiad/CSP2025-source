#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=205;
int n,cnt,m,h=1,l=1,f;
int a[N];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
		a[i]=-a[i];
	}
	cnt=-a[1];
//	cout<<"cnt"<<cnt<<endl;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		a[i]=-a[i];
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt)
		{
			printf("%lld %lld",l,h);
			return 0;
		}
		if(f==0)
		{
			if(h==n)
			{
				l++;
				f=1;
				continue;
			}
			h++;
		}
		else if(f==1)
		{
			if(h==1)
			{
				l++;
				f=0;
				continue;
			}
			h--;
		}
	}
	return 0;
}
