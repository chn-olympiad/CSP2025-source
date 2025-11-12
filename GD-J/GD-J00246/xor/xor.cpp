#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=5e5+5;

int n,k;
int a[N];

map<int,int>mp;

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	_rep(i,1,n) cin>>a[i];
	
	mp[0]=0;
	int now=0,lst=0,ans=0,pos=0;
	_rep(i,1,n)
	{
		now=now^a[i];  
		
		if(mp.count(now^k))
		{
			if(mp[now^k]>=lst)
				ans++,lst=i;
		} 
		
		mp[now]=i;
	} 
	cout<<ans<<"\n";
	return 0;
} 

