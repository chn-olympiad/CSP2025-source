#include<bits/stdc++.h>
using namespace std;
long long dic[600];
const int maxn=10000086;
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a==0)
		{
			cnt++;
		}
		
	}
	dic[0]=1;
	if(n-cnt<0)
	{
		cout<<0<<endl;
	}
	for(int i=1;i<=n-cnt;i++)
	{
		dic[i]=dic[i-1]*i%maxn;
	}
	if(n-cnt>=m)
	{
		cout<<dic[n-cnt]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

