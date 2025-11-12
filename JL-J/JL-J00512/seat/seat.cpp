#include <bits/stdc++.h>
using namespace std;
long long n,m,k,cnt=0,tmp=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	int a[k];
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[0]) cnt++;
	}
	for(int j=1;j<=n;j++)
	{
		if(j%2!=0)
		{
			for(int i=1;i<=m;i++)
			{
				if(cnt==0) 
				{
					cout<<j<<" "<<i<<endl;
					tmp=0;
					break;
				}
				cnt--;
			}
		}
		else
		{
			for(int i=m;i>0;i--)
			{
				if(cnt==0) 
				{
					cout<<j<<" "<<i<<endl;
					tmp=0;
					break;
				}
				cnt--;
			}
		}
		if(tmp==0) break;
	}
	return 0;
}
