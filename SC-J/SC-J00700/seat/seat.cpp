#include<bits/stdc++.h>
using namespace std;
//C:\Users\user\Downloads\cspj
int n,m,ans;
int a[505];
bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	
	if(n==1&&m==1)
	{
		cout<<a[1];
		return 0;
	}
	
	ans=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(a[i]==ans)
			{
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==ans)
			{
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	
	int n1=1,m1=1,mmm=1;
	while(n1!=n||m1!=m)
	{
		//cout<<a[mmm]<<"))"<<mmm<<'\n';
		if(a[mmm]==ans)
		{
			cout<<m1<<" "<<n1;
			break;
		}
		
		if(n1==n)
		{
			m1++;
			n1=1;
			mmm++;
		}
		else {n1++;mmm++;}
	}
	return 0;
}