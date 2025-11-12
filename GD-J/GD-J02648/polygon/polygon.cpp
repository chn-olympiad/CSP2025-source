#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define ll long long
#define il inline
using namespace std;

const int MOD=998244353;
const int MAXN=5e3+7;
const int MAXM=5e3*2+7;

int n,a[MAXN],ans,f[MAXM],sum,fac[MAXN],maxx;

il int add(int A,int B) {return A+B>=MOD?A+B-MOD:A+B;}
il int sub(int A,int B) {return A-B<0?A-B+MOD:A-B;}
il int mul(int A,int B) {return 1ll*A*B>=MOD?1ll*A*B%MOD:A*B;}

il void Add(int &A,int B) {A+B>=MOD?A=A+B-MOD:A=A+B;}
il void Sub(int &A,int B) {A-B<0?A=A-B+MOD:A=A-B;}
il void Mul(int &A,int B) {1ll*A*B>=MOD?A=1ll*A*B%MOD:A=A*B;}

int qpow(int A,int B)
{
	int res=1;
	while(B)
	{
		if(B&1)
			Mul(res,A);
		Mul(A,A);
		B>>=1;
	}
	return res;
}

int inv(int x) {return qpow(x,MOD-2);}

//int C(int A,int B)
//{
//	return mul(fac[A],mul(inv(fac[B]),inv(fac[A-B]))); 
//}

int main()
{
	fre("polygon");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	ans=qpow(2,n);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		int qwq=0;
		for(int j=0;j+a[i]<=2*a[i];j++)
			Add(qwq,f[j]);
		Sub(ans,qwq);
		for(int j=2*maxx;j>=a[i];j--)
		{
			f[j]=add(f[j],f[j-a[i]]);
		}
	}
	Sub(ans,1);
	printf("%d",ans);
	return 0;
}
