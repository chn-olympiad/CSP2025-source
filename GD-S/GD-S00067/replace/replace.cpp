#include<bits/stdc++.h>
using namespace std;
const long long mod=10000000000000949ll;
__int128 pw[5000006];
const int N=2e5+5;
__int128 H1[N],H2[N],hhh1[N],hhh2[N];
int m1,m2,n,q;
vector<int> f[N],v;
char s1[5000006],s2[5000006];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5000000;i++)pw[i]=pw[i-1]*1919810%mod;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s %s",s1+1,s2+1);
		int l=strlen(s1+1);
		bool fl=false;
		__int128 h1=0,h2=0;
		for(int i=1;i<=l;i++)
		{
			if(s1[i]!=s2[i])fl=true;
			if(fl)h2=(h2*114514+1049*s1[i]+s2[i])%mod;
			else h1=(h1*1919810+s1[i])%mod;
		}
		H1[i]=hhh1[i]=h1;
		H2[i]=hhh2[i]=h2;
	}
	sort(H1+1,H1+n+1);
	m1=unique(H1+1,H1+n+1)-H1-1;
	sort(H2+1,H2+n+1);
	m2=unique(H2+1,H2+n+1)-H2-1;
	for(int i=1;i<=n;i++)
	{
		hhh1[i]=lower_bound(H1+1,H1+m1+1,hhh1[i])-H1;
		hhh2[i]=lower_bound(H2+1,H2+m2+1,hhh2[i])-H2;
		f[hhh2[i]].push_back(hhh1[i]);
	}
	for(int i=1;i<=m2;i++)sort(f[i].begin(),f[i].end()); 
	while(q--)
	{
		scanf("%s %s",s1+1,s2+1);
		int l=strlen(s1+1),__l=strlen(s2+1);
		if(__l!=l){printf("0\n");continue;}
		int lst;
		for(int i=l;i>=1;i--)
		{
			if(s1[i]!=s2[i])
			{
				lst=i;
				break;
			}
		}
		bool fl=false;
		__int128 h2=0;
		int ans=0;
		for(int i=1;i<=l;i++)
		{
			if(!fl&&s1[i]!=s2[i])
			{
				fl=true;
				for(int j=0;j<i;j++)
				{
					__int128 tmp=(hhh1[i-1]-hhh1[j]*pw[i-j-1]%mod+mod)%mod;
					int x=lower_bound(H1+1,H1+m1+1,tmp)-H1;
					if(H1[x]==tmp)v.push_back(x);
				}
				sort(v.begin(),v.end());
			}
			if(fl)
			{
				h2=(h2*114514+1049*s1[i]+s2[i])%mod;
				if(i<lst)continue;
				int x=lower_bound(H2+1,H2+m2+1,h2)-H2;
				if(H2[x]==h2)
				{
					for(int j=0,k=0;j<v.size();j++)
					{
						while(k<f[x].size()&&f[x][k]<v[j])k++;
						while(k<f[x].size()&&f[x][k]==v[j])k++,ans++;
						if(k==f[x].size())break;
					}
				}
			}
			else
			{
				hhh1[i]=(hhh1[i-1]*1919810+s1[i])%mod;
			}
		}
		printf("%d\n",ans);
		v.clear();
	}
	return 0;
}
