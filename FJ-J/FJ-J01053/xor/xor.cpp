#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,k;
int a[N],xo[N];
bool vis[N];
bool f1=true,f2=true;
vector<pair<int,int> >v;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=1)f1=false;
		if(a[i]!=1&&a[i]!=0)f2=false;
	}
	if(f1)
	{
		printf("%d",n/2);
		return 0;
	}
	if(f2)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)cnt++;
		}
		if(k==0)printf("%d",cnt/2);
		else printf("%d",cnt);
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			v.push_back(make_pair(i,i));
			cnt++;
		}
		xo[i]=xo[i-1]^a[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l<=n-len+1;l++)
		{
			int r=l+len-1;
			bool flag=false;
			for(int o=0;o<v.size();o++)
			{
				if((l>=v[o].first&&l<=v[o].second)||(r>=v[o].first&&r<=v[o].second)||(l<=v[o].first&&r>=v[o].second))
				{
					flag=true;
					break;
				}
			}
			if(flag)continue;
			int ans=xo[r]^xo[l-1];
			if(ans==k)
			{
				cnt++;
				v.push_back(make_pair(l,r));
			}
		}
	}
	printf("%d",cnt);
	return 0;
}

