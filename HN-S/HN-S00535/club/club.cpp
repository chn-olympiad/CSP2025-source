#include <bits/stdc++.h>
#define M 100005
using namespace std;

int n,n1,s[3],m[M][3];
unsigned long long ans[6];

void f(unsigned long long a,int k,int t)
{
	if(k>=n)
	{
		if(a>ans[t])
		{
			ans[t]=a;
		}
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(s[i]>=n1)
		{
			continue;
		}
		a+=m[k][i];
		s[i]++;
		f(a,k+1,t);
		s[i]--;
		a-=m[k][i];
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	memset(ans,0,T);
	for(int t=0;t<T;t++)
	{
		memset(s,0,3);
		cin>>n;
		n1=n/2;
		for(int i=0;i<n;i++)
		{
			cin>>m[i][0]>>m[i][1]>>m[i][2];
		}
		f(0,0,t);
	}
	for(int t=0;t<T-1;t++)
	{
		cout<<ans[t]<<'\n';
	}
	cout<<ans[T-1];
	return 0;
}
