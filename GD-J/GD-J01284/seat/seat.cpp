#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll a[N][N],b[N];
ll  n,m,ans,res,cnt;
bool cmp(ll a,ll b)
{
	if(a!=b) return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	res=b[1];
	sort(b+1,b+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)  cout<<b[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				a[j][i]=b[cnt];
				if(b[cnt]==res)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				a[j][i]=b[cnt];
				if(b[cnt]==res)
				{
					cout<<j<<' '<<i<<endl;
					return 0;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

