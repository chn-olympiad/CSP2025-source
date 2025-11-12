#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Node 
{
	int l,r;
}a[1000005];
int top;

bool cmp (Node a,Node b)
{
	if(a.r!=b.r) return a.r<b.r;
	else return a.l>b.l;
}

int n,k;
int t;
int s[1005];
int ans;
signed main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>t,s[i]=s[i-1]^t;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if((s[j]^s[i-1])==k) a[++top].l=i,a[top].r=j;
	sort(a+1,a+top+1,cmp);
	t=0;
	for(int i=1;i<=top;++i)
		if(a[i].l>t) ++ans,t=a[i].r;
	cout<<ans;
	return 0;
}
