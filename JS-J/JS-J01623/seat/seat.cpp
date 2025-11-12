#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	for(int i=0;i<m;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++)
				if(a[i*n+n-j+1]==r)
				{
					cout<<i+1<<" "<<j<<endl;
					return 0;
				}
		}
		else
		{
			for(int j=n;j>=1;j--)
				if(a[i*n+j]==r)
				{
					cout<<i+1<<" "<<j<<endl;
					return 0;
				}
		}
	}
	return 0;
}
