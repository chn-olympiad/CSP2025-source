// T3 AC
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n,k,a[N],s[N];

map<int,int> mp;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]),s[i] = s[i - 1] ^ a[i]; 
	
	int cnt = 0; mp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(mp.count(s[i] ^ k))
		{
			cnt++;
			mp.clear(); mp[s[i]] = i;
			continue;
		}
		mp[s[i]] = i;
	}
	printf("%d\n",cnt);
	return 0;
}
/*
s[i] = s[i - 1] ^ a[i]
Step 1: Find r_min, [l,r_min] = k { Use Map ; }
Step 2: Greedy
let l = r + 1,Jump Find Next

This Greedy is True
It's Segment Cover Question
*/

