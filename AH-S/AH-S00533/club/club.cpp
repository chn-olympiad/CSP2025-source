#include<bits/stdc++.h>
using namespace std;
bool p1=1,p2=1;
int t,n,a1,a2,a3;
long long temp,ans;
int l1[100000],l2[100000],l3[100000];
bool cmp(int a,int b){return a>b;}
void dfs(int x)
{
	if (x==n) {ans=max(ans,temp);return ;}
	if (a1<n/2) {temp+=l1[x],a1++;dfs(x+1);temp-=l1[x],a1--;}
	if (a2<n/2) {temp+=l2[x],a2++;dfs(x+1);temp-=l2[x],a2--;}
	if (a3<n/2) {temp+=l3[x],a3++;dfs(x+1);temp-=l3[x],a3--;}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d %d %d",&l1[i],&l2[i],&l3[i]);
			if (l2[i]) p1=0;
			if (l3[i]) p2=0;
		}
		if (n<=10) {temp=ans=a1=a2=a3=0;dfs(0);printf("%lld\n",ans);}
		else if (p1&&p2)
		{
			sort(l1,l1+n,cmp);
			for (int i=0;i<n/2;i++) ans+=l1[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
