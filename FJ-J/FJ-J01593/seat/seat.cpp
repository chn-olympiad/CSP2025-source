#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],num,cnt;
bool cmp(int a,int b)
{
	if(a>b)
		return true;
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);	
	for(int i=1;i<=m;++i)
	{
		if(i%2)
			for(int j=1;j<=n;++j)
			{
				cnt++;
				if(a[cnt]==num)
				{
					cout<<i<<" "<<j;
					return 0;
				}	
			}
		else
			for(int j=n;j>=1;--j)
			{
				cnt++;
				if(a[cnt]==num)
				{
					cout<<i<<" "<<j;
					return 0;
				}	
			}
	}		
	return 0;
}
