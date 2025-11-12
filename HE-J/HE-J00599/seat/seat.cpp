#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

bool cmp(int x,int y){return x>y;}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	vector<int> s(n*m);
	for(int i=0;i<n*m;i++) cin>>s[i];
	int x=s[0],idx;
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<n*m;i++)
		if(x==s[i])
		{
			idx=i+1;
			break;
		}
	if(idx%n==0)
	{
		if((idx/n)&1) cout<<(idx/n)<<" "<<n;
		else cout<<(idx/n)<<" "<<1;
	}
	else
	{
		if(((idx+n-1)/n)&1) cout<<((idx+n-1)/n)<<" "<<(idx%n);
		else cout<<((idx+n-1)/n)<<" "<<n+1ll-(idx%n);
	}
	
	return 0;
}
