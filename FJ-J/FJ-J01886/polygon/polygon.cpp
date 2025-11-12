#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define TNF 0x3f3f3f3f3f3f3f3f
using namespace std;
int mod=998244353; 
int n,cnt,m;
int a[5100];
bool st[5100];
int sum;
vector<int>v;
void d(int y,int fa)
{
	if(y==m+1)
	{
		int sum=0,mx=-TNF;
		for(auto i:v)
		{
			sum+=i;
			mx=max(mx,i);
		}
		if(sum>mx*2)
		{
			cnt++;
			cnt%=mod;
		}
		return ;
	}
	for(int i=fa;i<=n;i++)
	{
		if(st[i])continue;
		v.push_back(a[i]);
		st[i]=1;
		d(y+1,i);
		st[i]=0;
		v.pop_back();
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		m=i;
		d(1,1);
	}
	cout<<cnt<<endl;
	return 0;
} 

