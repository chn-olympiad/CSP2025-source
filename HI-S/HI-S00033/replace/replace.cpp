#include <bits/stdc++.h>
#define _F(x,y,z) for(int x=y;x<=z;x++)
#define F_(x,y,z) for(int x=y;x>=z;x--)
#define TF(x,y,z) for(int x=head[y],z,;x;x=nex[x])

using namespace std;

typedef long long ll;
typedef const int ci;
typedef double dou;
typedef pair<ll,ll> pii;

ci maxn=5e6+10,p=1e9+7;
int n,m,q,cnt;
char s[maxn],s2[maxn];
string ss[200010],ss2[200010];
pii a[maxn],hass[maxn];
ll ht1[maxn],ht2[maxn];
map<pii,vector<int> >mp;
void work()
{
	scanf("%d%d",&n,&q);
	_F(i,1,n)
	{
		scanf("%s%s",s+1,s2+1);
		int len=strlen(s+1),fl=0,l=1,r=0;
//		_F(j,1,len)
//		ss[j]=s,ss2[i]=s2;
		ll has1=0,has2=0,has3=0,has4=0;
		while(s[len]==s2[len]&&len>0) len--,r++;
		if(len==0) continue;
		_F(j,1,len)
		{ 
			if(s[j]!=s2[j])
				fl=1;
			if(fl)
				has1=(has1*31+s[j]-'a')%p,has2=(has2*31+s2[j]-'a')%p;
		}
		while(s[l]==s2[l]) l++;
		l--; 
		a[i]={l,r};
		F_(j,l,1)
			has3=(has3*31+s[j]-'a')%p;
		_F(j,1,r)
			has4=(has4*31+s[len+j]-'a')%p;
		hass[i]={has3,has4};
		mp[{has1,has2}].push_back(i);
	}
	while(q--)
	{
		scanf("%s%s",s+1,s2+1);
		int len=strlen(s+1),fl=0,cnt=0,l=1,r=0,len2=strlen(s2+1);
		if(len!=len2)
		{
			puts("0");
			continue;
		}
		ll has1=0,has2=0;
		while(s[len]==s2[len]) len--,r++;
		_F(j,1,len)
		{ 
			if(s[j]!=s2[j])
				fl=1;
			if(fl)
				has1=(has1*31+s[j]-'a')%p,has2=(has2*31+s2[j]-'a')%p;
		}
		while(s[l]==s2[l]) l++;
		l--; 
		ht1[1]=s[l]-'a';
		_F(j,2,l)
			ht1[j]=(ht1[j-1]*31+s[l-j+1]-'a')%p;
		ht2[1]=s[len+1]-'a';
		_F(j,2,r)
			ht2[j]=(ht2[j-1]*31+s[j+len]-'a')%p; 
		for(int x:mp[{has1,has2}])
		{
			if(hass[x].first==ht1[a[x].first]&&hass[x].second==ht2[a[x].second])
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	int t,c;
//	scanf("%d%d",&c,&t);
//	while(t--)
		work();
	fclose(stdin);
	fclose(stdout);
}


