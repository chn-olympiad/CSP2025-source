#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;
int n,kx,k,ans;
ll a[MAXN],s[2][MAXN];
bool f=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[0][i]=s[0][i-1]^a[i];
		s[1][i]=s[0][i]^k;
	}
//	if(s[0][n]!=0&&s[0][n]!=k)
//	{
//		printf("0");
//		return 0;
//	}
	for(int i=1;i<=n;i++)
	{
//		cout<<s[0][i]<<" "<<s[1][i]<<'\n';
		if(s[f][i]==k)
		{
			ans++;
			if(f==1) f=0;
			else f=1;
		}
	}
	printf("%d",ans);
	return 0;
}
