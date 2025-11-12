#include<bits/stdc++.h>
using namespace std;
int a[1000],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			cnt=i;
			break;
		}
	}
	
	cout<<cnt/m+1;
	int b=cnt/m+1;
	if(b%2==0)
	{
		int s=n-(cnt%m)+1;
		cout<<" "<<s;
		return 0;
	}
	cout<<" "<<cnt%m;
	return 0;
}

