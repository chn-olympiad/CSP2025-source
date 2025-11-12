#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int a[500010],v[2000010],p[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,t=0,s=0;
	cin>>n>>k;
	v[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		s^=a[i];
		if(v[s^k]>0)
		{
			t++;
			for(int j=1;j<=p[0];j++)
				v[p[j]]=0;
			v[0]=1;
			p[0]=0;
			s=0;	
		}	
		else
		{
			v[s]=1;
			p[++p[0]]=s;
		}
	}
	cout<<t;
	return 0;
}

