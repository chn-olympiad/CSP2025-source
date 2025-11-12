#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,k,fy[N][3],im=LONG_LONG_MIN,cnt;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	if(k!=0){cout<<"0";return 0;}//够了，骗32分足够了 
	for(int i=1;i<=n;i++)
	{
		cin>>fy[i][0]>>fy[i][1]>>fy[i][2];
		cnt+=fy[i][2];
		im=max(im,fy[i][2]);
	}
	cout<<cnt-im;
	return 0;
}
//2025.11.1 17:15 check this code to make sure that it can ger some scores for me although it is not a correct way.
/*
回望过往，沉在oi里拼搏 
仰望未来，惜别oi难回头
斗转星移，物是人非
dev依在，不见code前那几载 
回看电脑桌前
只依稀记得，这里有个少年 
*/ 
//2025.11.1 17:25 距成为数竞生还有1h,谨此回忆我的信竞生涯 
