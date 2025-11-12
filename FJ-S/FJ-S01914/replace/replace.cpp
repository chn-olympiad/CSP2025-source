#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e5+5,M=5e6+5;
int n,q;
int lens[N];
long long ans;
ll vals1[N],vals2[N],hv[M],valt1[M],valt2[M];
char chs1[M],chs2[M],cht1[M],cht2[M];
ll get1(int l,int r)
{
	return valt1[r]-valt1[l-1]*hv[r-l+1];
}
ll get2(int l,int r)
{
	return valt2[r]-valt2[l-1]*hv[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=10000000)
	{
		hv[0]=1;
		for(int i=1;i<=5000000;i++) hv[i]=hv[i-1]*(ll)(137);
		for(int i=1;i<=n;i++)
		{
			scanf("%s%s",chs1+1,chs2+1),lens[i]=strlen(chs1+1);
			for(int j=1;j<=lens[i];j++) vals1[i]=vals1[i]*(ll)(137)+(chs1[j]-'a'+1);
			for(int j=1;j<=lens[i];j++) vals2[i]=vals2[i]*(ll)(137)+(chs2[j]-'a'+1);
		}
		for(int T=1;T<=q;T++)
		{
			scanf("%s%s",cht1+1,cht2+1),ans=0; int lent,lent1=strlen(cht1+1),lent2=strlen(cht2+1),L,R;
			if(lent1^lent2){puts("0"); continue;}
			lent=lent1;
			for(int i=1;i<=lent;i++) if(cht1[i]!=cht2[i]){L=i; break;}
			for(int i=lent;i;i--) if(cht1[i]!=cht2[i]){R=i; break;}
			for(int i=1;i<=lent;i++) valt1[i]=valt1[i-1]*(ll)(137)+(cht1[i]-'a'+1);
			for(int i=1;i<=lent;i++) valt2[i]=valt2[i-1]*(ll)(137)+(cht2[i]-'a'+1);
			for(int i=1;i<=n;i++)
			{
				for(int l=min(L,lent-lens[i]+1);l;l--)
				{
					int r=l+lens[i]-1;
					if(r<R) break;
					if(get1(l,r)==vals1[i]&&get2(l,r)==vals2[i]) ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
