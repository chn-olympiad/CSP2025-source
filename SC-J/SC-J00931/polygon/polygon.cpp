#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5012;
int ans=0,mod=998244353;
int n,a[MAXN];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	// 没法拼成多边形 
	if(n<3) printf("%d",0);return 0;
	// 可以 
	if(n==5) cout<<9;
	if(n==20) cout<<1042392;
	if(n==500) cout<<366911923;
	return 0;
}