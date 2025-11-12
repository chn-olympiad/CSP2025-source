#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,a[N],gr,pl;
bool cmp(int c,int d)
{
	return (c>d);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++)
		cin>>a[i];
	gr=a[1];
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		if(a[i]==gr)
		{
			pl=i;
			break;		
		}
	}
	int ans1=1,ans2=0;
	bool di=true;
	for(int i=1;i<=pl;i++)
	{
		if(di)
		{
			if(ans2<n)
				ans2++;
			else if(ans2==n)
			{
				ans1++;
				di=false;
			}
		}
		else
		{
			if(ans2>1)
				ans2--;
			else if(ans2==1)
			{
				ans1++;
				di=true;
			}
		}

	}

	cout<<ans1<<" "<<ans2;
	
	
	return 0;
}
