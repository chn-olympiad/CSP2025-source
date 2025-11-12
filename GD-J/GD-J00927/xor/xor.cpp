#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<20)+10;
int n,k;
int a[maxn],lst[maxn],mx[maxn];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	for(int i=0;i<(1<<20);i++) lst[i]=-1;
	lst[0]=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		if(lst[a[i]^k]!=-1) x=mx[lst[a[i]^k]]+1;
		lst[a[i]]=i,mx[i]=max(mx[i-1],x);
	}
	cout<<mx[n];
	return 0;
}
