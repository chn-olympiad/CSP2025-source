#include<bits/stdc++.h>
using namespace std;
#define L long long
#define S string
#define B bool
#define C char
#define I cin
#define O cout
#define V vector
signed main()
{
	//骗分代码 >=30
	//唯一识别码：fwerefvfvczddsddfdsfdadsaxaxxapl
	ios::sync_with_stdio(0);
	I.tie(0);
	O.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	L num,fin,ans=0,now=0;
	I>>num>>fin;
	V<L> a(num+1);
	for(L i0=0;i0<=num-1;i0++)
	{
		I>>a[i0];
		now^=a[i0];
		if(now==fin)
		{
			ans++;
			now=0;
		} 
	}
	O<<ans;
	return 0;
}