#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n,m,p[501],able_cnt=0;
bool state=1;
char hard[501];


bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> hard[i];
		if(hard[i]!='1')
			state=0;
		if(hard[i]=='1')
			able_cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> p[i];
	}
	
	if(able_cnt<m)
	{
		cout << 0;
		return 0;
	}
	
	if(m==1)
	{
		long long ans=0;
		int beicheng=0;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(p[i]>0)	beicheng++;		
		}
		long long cheng=1;
		int delta=n;
		while(n--)
		{
			cheng=cheng*delta%MOD;
			delta--;
		}
		for(int i=1;i<=beicheng;i++)
		{
			ans+=cheng%MOD;
		}
		cout << ans%MOD;
		return 0;
	}
//	if(n==m)
//	{
//		int title[501];
//		for(int i=n,j=1;i>0;i--,j++)
//		{
//			if(hard[j]=='0')
//				title[i]
//				
//		}	
//	}
} 
