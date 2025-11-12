#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],cnt=1,cnt1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) cnt++; 
	}
	sort(a,a+n+1);
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		if(f)
		{
			for(int j=1;j<=m;j++) 
			{
				cnt1++;
				if(cnt1==cnt)
				{
					cout<<i<<" "<<j;
						fclose(stdin);
						fclose(stdout); 
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--) 
			{
				cnt1++;
				if(cnt1==cnt)
				{
					cout<<i<<" "<<j;
						fclose(stdin);
						fclose(stdout); 
					return 0;
				}
			}
		}
		f=!f;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
