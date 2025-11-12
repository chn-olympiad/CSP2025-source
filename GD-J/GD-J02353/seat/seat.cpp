#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],rm,ansn,ansm; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++) cin>>a[i];
	rm=a[0];
	sort(a,a+n*m);
	for(long long i=0;i<m;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(i%2==0&&rm==a[(i-1)*m+j])
			{
				cout<<i<<" "<<j;
				return 0;
			}
			if(i%2==1&&rm==a[(i-1)*m+n-j])
			{
				cout<<i<<" "<<n-j;
				return 0;
			}
		}
	}
	return 0;
}
//8:40 创建文件。
//9:30 做完，难度红~橙，预计 100pts 
