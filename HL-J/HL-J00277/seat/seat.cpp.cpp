#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,cnt,m,r;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		cin>>a[i];
		r=a[0];
		while(r<a[i+1])
		{
			cnt++;
			continue;
			if(r>a[i+1])
			{
				if(cnt>n)
				{
					m+=cnt/n+1;
					if(m%2==0)
					{
						n-=n%cnt;
					}
					else if(m%2==1)
					{
						n+=n%cnt;
					}
				}
				else if(n>=cnt)
				{
					n+=cnt;
				}
			}
			else if(r<a[i+1])
			{
				cnt++;
				continue;
			}
		}
		if(r>a[i+1])
		{
			cout<<1<<" "<<1;
			return 0;
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
