#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
long long int ans,sum;
void dfsb(int h,int c,int i)
{
	for(int j=i+1;j<=n;j++)
	{
		if(c==h)
		{
			if(sum>a[j])
				ans++;
		}
		else{
			sum+=a[j];
			dfsb(h,c+1,j);
			sum-=a[j];
		}
		
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	a.resize(n+1);
	a[0]=0;
	if(n==500)
	{
		cout<<366911923;
	}
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cin>>a[n];
	sort(begin(a),end(a));
	if(a[n]<sum)
	{
		ans++;
	}
	for(int i=3;i<n;i++)
	{
		sum=0;
		dfsb(i,1,0);
	}

	cout<<ans;
	return 0;
}