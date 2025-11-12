#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
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
#define gc getchar
#define pc puchar
template<typename T=long long>
T qread(){int r=0;char c=gc();while(c<'0'||c>'9')c=gc();while('0'<=c&&c<='9')r=(r*10)+c-'0',c=gc();return r;}
template<typename T=int> void _print(T x){if(!x)return;_print(x/10),pc(x%10+'0');}
}
int n,m;
int x,a;
int cnt;
int ansx,ansy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		if(i==1) scanf("%d",&x);
		else scanf("%d",&a),cnt+=(a>x);
	}
	ansx=ansy=1;
	while(cnt--)
	{
		if(ansx&1) ansy++;
		else ansy--;
		if(ansy==n+1) ansy=n,ansx++;
		if(ansy==0) ansy=1,ansx++;
	}
	printf("%d %d",ansx,ansy);
	return 0;
}
