#include<bits/stdc++.h>
using namespace std;
long long n,m,qp[20][20],t,ifind,cnt;
bool l;//0在奇数列从上往下 1在偶数列从下往上 
vector<int> v;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++)
	{
		cin>>t;
		if (i==0)ifind=t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	for (int j=1;j<=m;j++)//列 
	{
		if (l==0) 
		{
			for (int i=1;i<=n;i++)
			{
				cnt++;
				if (v[n*m-cnt]==ifind)
				{
					cout<<j<<" "<<i; 
					return 0;
				}
				v.pop_back();
			} 
		}
		else
		{
			for (int i=n;i>=1;i--)
			{
				cnt++;
				if (v[n*m-cnt]==ifind)
				{
					cout<<j<<" "<<i; 
					return 0;
				}
				v.pop_back();
			} 
		}
		if (l==1)l=0;
		else l=1;
	}	
	return 0;
}
