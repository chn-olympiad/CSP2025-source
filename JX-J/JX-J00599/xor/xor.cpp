#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n,ans;
int l = 2,r;
long long k;
long long a[maxn],s[maxn];
bool check(int x)
{
    int i = 1;
	bool f = 0;
    while(i <= n)
    {
		if((s[i + x - 1] xor s[i - 1]) == k && (i + x - 1 <= n))
		{
			f = 1;
			ans ++;
			if(i + x <= n) i += x;
			else break;
		}
		else
		{
			if(i + x - 1 <= n) i ++;
			else break;
		}
	}
    return f;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i] = (s[i - 1] xor a[i]);
        if(a[i] == k) ans ++;
    }
    r = n;
    while(l <= r)
    {
        int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n",ans);
    return 0;
}