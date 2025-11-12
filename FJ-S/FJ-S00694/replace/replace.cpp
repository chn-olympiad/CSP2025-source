#include<bits/stdc++.h>//17:25 try   time
using namespace std;
const long long N=2e5+11,M=3e6+11,mod=1e9+7,modd=1e9+9;
char z[M],zz[M];
long long p=131,sum[M],pp[M];
struct zhx{
	long long c,len,sum,f;
}c[N];
bool cmp(zhx a,zhx b)
{
	return a.c<b.c;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,lenn,cc,fi,l,r,mid,ans,x,y;
	pp[1]=p;
	for(long long i=2; i<=3e6; i++)
		pp[i]=pp[i-1]*p%mod;
	cin>>n>>q;
	for(long long i=1; i<=n; i++)
	{
		scanf("%s",z+1),scanf("%s",zz+1);
//		cin>>z+1,cin>>zz+1;
		c[i].len=strlen(z+1);
//		for(long long j=1; j<=c[i].len; j++)
//			cout<<z[j];
//		cout<<endl;
//		for(long long j=1; j<=c[i].len; j++)
//			cout<<zz[j];
//		cout<<endl;
		
		for(long long j=1; j<=c[i].len; j++)
		{
			c[i].sum=(c[i].sum*p%mod+int(z[j]-'a')+1)%mod;
			if(z[j]!=zz[j])
			{
				if(c[i].c==0)
					c[i].f=j;
				c[i].c=c[i].c*p%mod;
				c[i].c=(c[i].c+int(zz[j]-z[j])+26)%mod;
			}
		}
	}
	sort(c+1,c+1+n,cmp);
//	for(int i=1; i<=n; i++)
//		cout<<c[i].c<<' '<<c[i].f<<' '<<c[i].len<<' '<<c[i].sum<<endl; 
//	cout<<endl;
	while(q--)
	{
		scanf("%s",z+1),scanf("%s",zz+1);
		lenn=strlen(z+1);
		ans=fi=cc=0;
		for(long long i=1; i<=lenn; i++)
		{
			if(z[i]!=zz[i])
				cc=(cc*p%mod+(z[i]==zz[i]?0:(zz[i]-z[i]+26)))%mod;
			if(cc!=0 && fi==0)
				fi=i;
			sum[i]=sum[i-1]*p%mod+int(z[i]-'a')+1;
		}
//		cout<<fi<<endl;
		l=1,r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(c[mid].c<cc)
				l=mid+1;
			else
				r=mid;
		}
		for(long long i=l; i<=n; i++)
			if(c[i].c!=cc)
				break;
			else
			{
				x=fi-c[i].f,y=fi+(c[i].len-c[i].f);
//				cout<<x<<' '<<y<<endl;
				if(x<0 || y>lenn)
					continue;
				if((sum[y]-sum[x]*pp[y-x]%mod+mod)%mod==c[i].sum)
					ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
/*

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb




3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
