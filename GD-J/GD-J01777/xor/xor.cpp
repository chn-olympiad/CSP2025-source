#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int n,k,a[500005],s[500005],cz[500005],t;
int f[1048580];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1] xor a[i];
		t=s[i] xor k;
		if(f[t]>0)
		{
			cz[i+1]=max(cz[f[t]+1]+1,cz[i+1]);
		}
		if(s[i]==k)cz[i+1]=max(1,cz[i+1]);
		if(a[i]==k)cz[i+1]=max(cz[i+1],cz[i]+1);
		cz[i+1]=max(cz[i+1],cz[i]);
		f[s[i]]=i;
	}
	cout<<cz[n+1];
	return 0;
}
