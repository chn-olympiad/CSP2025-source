#include<bits/stdc++.h>
using namespace std;
#define llt long long
const int N=2e5+5,L=5e6+5,V=23,mod=1e9+7;
char t1[N],t2[N],tmp[N];
int n,q,m,ans,l[N];
llt a[N][2],fac[L];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fac[0]=1;for(int i=1;i<L;i++) fac[i]=fac[i-1]*V%mod;
	scanf("%d%d",&n,&q);
	for(int i=1,flag;i<=n;i++)
	{
		char c=getchar();
		flag=-1;
		while(1)
		{
			if(c>='a'&&c<='z')
			{
				if(flag==-1) flag=0;
				if(flag==0) l[i]++;
				a[i][flag]=(a[i][flag]*V%mod+(c-'a'+1))%mod;
			}
			else
			{
				if(flag==1) break;
				if(flag==0) flag++;
			}
			c=getchar();
		}
	}
//	for(int i=1;i<=n;i++) cout<<l[i]<<"   "<<a[i][0]<<' '<<a[i][1]<<endl;
	while(q--)
	{
		ans=0;
		scanf("%s",t1+1);scanf("%s",t2+1);
		m=strlen(t1+1);
//		for(int i=1;i<=m;i++) cout<<t1[i];cout<<"  ";
//		for(int i=1;i<=m;i++) cout<<t2[i];cout<<'\n';
		for(int i=1;i<=n;i++)
		{
			llt has10=0,has11=0,has12=0,has20=0,has21=0,has22=0;
			for(int j=1;j<=m;j++)
			{
				has12=(has12*V%mod+(t1[j]-'a'+1))%mod;
				has22=(has22*V%mod+(t2[j]-'a'+1))%mod;
			}
			for(int j=1;j<=m;j++)
			{
				has11=(has11*V%mod+(t1[j]-'a'+1))%mod;
				has21=(has21*V%mod+(t2[j]-'a'+1))%mod;
				has12=(has12+mod-fac[m-j]*(t1[j]-'a'+1)%mod)%mod;
				has22=(has22+mod-fac[m-j]*(t2[j]-'a'+1)%mod)%mod;
//				cout<<t1[j]<<' '<<t2[j]<<endl;
//				cout<<has1<<' '<<has2<<"  ";
				if(j>l[i])
				{
					has10=(has10*V%mod+(t1[j-l[i]]-'a'+1))%mod;
					has11=(has11+mod-fac[l[i]]*(t1[j-l[i]]-'a'+1)%mod)%mod;
					has20=(has20*V%mod+(t2[j-l[i]]-'a'+1))%mod;
					has21=(has21+mod-fac[l[i]]*(t2[j-l[i]]-'a'+1)%mod)%mod;
				}
//				cout<<has1<<' '<<has2<<endl;
//				cout<<has10<<' '<<has11<<' '<<has12<<"  "<<has20<<' '<<has21<<' '<<has22<<'\n';
//				cout<<i<<' '<<j<<endl;
				if(j>=l[i]) if(has11==a[i][0]&&has21==a[i][1])
				{
					llt all1=(has12+has21*fac[m-j]%mod+has10*fac[m-j+l[i]]%mod)%mod;
					llt all2=(has22+has21*fac[m-j]%mod+has20*fac[m-j+l[i]]%mod)%mod;
					if(all1==all2){ans++;break;}
				}
			}
//			cout<<endl;
		}
		printf("%d\n",ans);
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
*/
