#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[500001],w[2000001];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s[i]=s[i-1]^x;
	}
	w[0]=1;
	int ss=0,la=0;
	for(int i=1;i<=n;i++)
	{
		int nown=s[i]^k;
		if(w[nown]!=-1&&w[nown]>la)
			ss++,la=i;
		w[s[i]]=i+1;
	}
	cout<<ss<<"\n";
	return 0;
}
