#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
const int N=1e+5+10;
int a1[N],a2[N],a3[N];
int b1,b2,b3,bm[N];
int main()
{
	freopen("stdin.club","r",stdin);
	freopen("stdout.club","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int maxn[N]={-1};
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+n+1);
		int x=0;
		for(int i=n;i>=1;i--)
		{
			if(x<n/2)
			{
				sum+=a1[i];
				x++;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
