//Ê²Ã´¶¼Íü²»µô¡£
//The top of Human's Ranking: Lucky Seven.
//I won't lose you.
#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
const int Mod=998244353;
int n,ans=0;
int a[N];
bool cmp(int x,int y){return x<y;}
void go(int x,int y,int z)
{
	if(y==x)
	{
		if(z>a[x])ans=(ans+1)%Mod;
		return;
	}
	go(x,y+1,z);
	go(x,y+1,z+a[y]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(i=3;i<=n;i++)
		go(i,1,0);
	printf("%d",ans);
	return 0;
}
