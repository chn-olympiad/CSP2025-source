#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int n,m,a[105],r,id;
bool cmp(int x,int y)
{
	return x > y;
}
signed main()
{
	FILE("seat");
	ioimprove();
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++) cin>>a[i];
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
		if(a[i] == r) id = i;
	int tmp1 = id / (2 * n),tmp2 = id % (2 * n);
	if(!tmp2) tmp2 = 2 * n;
	cout<<tmp1 * 2 + ((tmp2 > n) ? 2 : 1)<<" "<<((tmp2 > n) ? (2 * n + 1 - tmp2) : tmp2);
	
	return 0;
}
