#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull ans;
unsigned int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		ans=ans+w; 
	}
	printf("%lld",ans);
}
/*
不会，我图论跟不会没什么区别了 
希望能有一点分QAQ 
*/
//I think I may be 3~2=
//QAQ
//freeopen(免费开启) 
//froepen
//freopen
//zto 大佬们 orz 
