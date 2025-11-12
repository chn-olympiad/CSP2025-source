#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	vector<int>v(n*m+1);
	for(int i=1;i<=n*m;i++) cin>>v[i];
	int s=v[1];
	sort(v.begin()+1,v.end(),greater<int>());
	int idx=0;
	for(int i=1;i<=n*m;i++)
	{
		if(v[i]==s)
		{
			idx=i;
			break;
		}	
	} 
	if(idx<=n) cout<<1<<" "<<idx<<endl;
	else
	{
		int c=idx/n;
		int r=0;
		if(idx%n) c++;
		if(c%2) r=idx%n;
		else r=n-(idx%n-1);
		cout<<c<<" "<<r<<endl;
	}
	return 0;
}
