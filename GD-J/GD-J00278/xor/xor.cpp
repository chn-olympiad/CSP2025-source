#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define ll long long
using namespace std;
const int maxn=500080;
int a[maxn];
int x[1099000],ind[1099000],f[maxn],maxf[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		x[i]=x[i-1]^a[i];
		if(ind[x[i]]!=0)
		{
			int t=ind[x[i]];
			f[i]=maxf[t]+1;
		}else{
			f[i]=(x[i]==k);
		}
		ind[x[i]^k]=i;
		maxf[i]=max(maxf[i-1],f[i]);
	}
	cout<<maxf[n];
	return 0;
 }

