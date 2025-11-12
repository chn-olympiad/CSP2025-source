#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
bool ok;
int n,k;
ll a[N],s[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]!=1)
			ok=1;
	}
	if(!ok)
	{
		cout<<n/2;
		return 0;
	}
	int t0=0,t1=0;
	for(int i=1;i<=n;i++)
		if(s[i]==0)
			t0++;
		else
			t1++;
	if(k==0)
		cout<<t0;
	else
		cout<<t1;
	return 0;
}
