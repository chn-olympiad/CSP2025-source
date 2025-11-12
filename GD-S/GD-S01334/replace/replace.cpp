#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
const int maxn=2e5+5,mod=998244353,base=131;
using ll=long long;
mt19937 rnd(time(0));
ll qz[30],pw[maxn],ha[maxn],ha1[maxn],ha2[maxn],ha3[maxn];
int n,m;
string s[maxn],s1[maxn];
pii calc(string &s)
{
	for(int i=0;i<s.size();i++)if(s[i]=='b')return {i,s.size()-i-1};
}
map<pii,int>f;
void read(string &s)
{
	int x=0;
	s="";
	char c=getchar();
	for(;c<'a' || c>'z';c=getchar());
	for(;c>='a' && c<='z';c=getchar())s+=c;
}
struct Query
{
	pii t;
	int id;
	int a,b;
}q[maxn<<1];
int Ans[maxn];
bool cmp(Query x,Query y)
{
	if(x.a==y.a)
	{
		if(x.b==y.b)return x.id<y.id;
		return x.b<y.b;
	}
	return x.a<y.a;
}
bool cmp1(Query x,Query y)
{
	if(x.b==y.b)return x.id<y.id;
	return x.b<y.b;
}
void cdq(int l,int r)
{
	if(l==r)return ;
	int mid=l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	sort(q+l,q+mid+1,cmp1);
	sort(q+mid+1,q+r+1,cmp1);
	int L=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(L<=mid && q[L].b<=q[i].b)
		{
			if(q[L].id==-1)f[q[L].t]++;
			L++;
		}
		if(q[i].id!=-1)Ans[q[i].id]+=f[q[i].t];
	}
	for(int i=L-1;i>=l;i--)if(q[i].id==-1)f[q[i].t]--;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		read(s[i]),read(s1[i]);
		len+=s[i].size(),len+=s1[i].size();
		pii t=calc(s1[i]),t1=calc(s[i]);
		t.first-=t1.first,t.second-=t1.second;
		q[++cnt]={t,-1,t1.first,t1.second};
	}
	if(len<=2000 && n<=2000 && m<=2000)
	{
		pw[0]=1;
		for(int i=1;i<=2000;i++)pw[i]=pw[i-1]*base%mod;
		for(int i=0;i<26;i++)qz[i]=rnd()%mod;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s[i].size();j++)
			{
				ha[i]=(ha[i]+pw[j]*qz[s[i][j]-'a'])%mod;
				ha1[i]=(ha1[i]+pw[j]*qz[s1[i][j]-'a'])%mod;
			}
		}
		for(int i=1;i<=m;i++)
		{
			string s2,s3;
			read(s2),read(s3);
			int ans=0;
			for(int j=0;j<s2.size();j++)
			{
				ha2[j]=(ha2[j-1]+pw[j]*qz[s2[j]-'a'])%mod;
				ha3[j]=(ha3[j-1]+pw[j]*qz[s3[j]-'a'])%mod;
			}
			for(int j=0;j<s2.size();j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(j<s[k].size()-1)continue;
					
					if(ha[k]*pw[j-s[k].size()+1]%mod==(ha2[j]-(j-s[k].size()>=0?ha2[j-s[k].size()]:0)+mod)%mod)
					{
						if(ha1[k]*pw[j-s1[k].size()+1]%mod==(ha3[j]-(j-s[k].size()>=0?ha3[j-s1[k].size()]:0)+mod)%mod)
						{
							if(j-s[k].size()>=0)
							{
								if(ha2[j-s[k].size()]==ha3[j-s[k].size()])
								{
									if((ha2[s2.size()-1]-ha2[j]+mod)%mod==(ha3[s3.size()-1]-ha3[j]+mod)%mod)ans++;
								}
							}
						}
					}
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		string s,s1;
		read(s),read(s1);
		pii t=calc(s1),t1=calc(s);
		t.first-=t1.first,t.second-=t1.second;
		q[++cnt]={t,i,t1.first,t1.second};
	}
	sort(q+1,q+cnt+1,cmp);
	cdq(1,cnt);
	for(int i=1;i<=m;i++)printf("%d\n",Ans[i]);
	return 0;
}
