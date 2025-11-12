#include <bits/stdc++.h>
using namespace std;
int t,n,num[5],sum,tot=1;
struct T
{
	int asd,mac,b,c;
} a[100005];
bool cmp(T x,T y)
{
	return x.mac<y.mac;
}
int main()
{
	cin >> t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	while(t--)
	{
		memset(a,sizeof(a),0);
		num[1]=0;
		num[2]=0;
		num[3]=0;
		sum=0;
		tot=1;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].asd >> a[i].b >> a[i].c;
			a[i].mac=max(a[i].asd,max(a[i].b , a[i].c))-(a[i].asd+a[i].b + a[i].c-max(a[i].asd,max(a[i].b , a[i].c))-min(a[i].asd,min(a[i].b , a[i].c)));
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].asd>max(a[i].b,a[i].c))
			{
				if(num[1]>=n/2)
				{
//					sort(a+1,a+i+1,cmp);
					sum+=a[i].asd;
					sum-=a[tot++].mac;
				}
				else
				{
					num[1]++;
					sum+=a[i].asd;
				}
			}
			else if(a[i].b>max(a[i].asd,a[i].c))
			{
				if(num[2]>=n/2)
				{
//					sort(a+1,a+i+1,cmp);
					sum+=a[i].b;
					sum-=a[tot++].mac;
				}
				else
				{
					num[2]++;
					sum+=a[i].b;
				}
			}
			else
			{
				if(num[3]>=n/2)
				{
//					sort(a+1,a+i+1,cmp);
					sum+=a[i].c;
					sum-=a[tot++].mac;
				}
				else
				{
					num[3]++;
					sum+=a[i].c;
				}
			}
		}
		cout << sum << endl; 
	}
	return 0;
}
