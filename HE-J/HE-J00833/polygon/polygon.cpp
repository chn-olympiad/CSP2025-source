#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
using namespace std;
const int Imax=0x7fffffff;
const long long LLmax=0x7fffffffffffffff;
namespace joker
{
template<typename T=long long>
T qread()
{int r=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while('0'<=c&&c<='9')r=(r*10)+c-'0',c=getchar();return r;}
int max(int a,int b){return a>b?a:b;}
}
const int N=5005;
const int M=3e7+5,Mod=998244353;
int n;
int a[N];
intt ans;
int sum[M];
int sm;
int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=sm;j++) ans=(ans+sum[j])%Mod;
		sm+=a[i];
		for(int j=sm;j>=a[i];j--) sum[j]=(sum[j]+sum[j-a[i]])%Mod;
	}
	printf("%lld",ans);
	return 0;
}
