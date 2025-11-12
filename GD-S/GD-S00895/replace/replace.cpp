#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int m1 = 7;
#define m2 13
const int mod1 = 1000000007;
#define mod2 1000000013
string a,b;
struct node
{
	int nxt[26];
	int jd;
	int num,p,dep;
	int fa;
	int b;
}s[2000005];
int tot;

void insert()
{
	int now=0;
	int sum1=0;
	for(int i=0; i < a.size(); i++ )
	{
		sum1*=m1;
		sum1%=mod1;
		sum1+=(b[i]-'a'+1);
		sum1%=mod1;
	}
	for(int i= 0; i < a.size(); i++ )
	{
		if(s[now].nxt[a[i]-'a']==0)
		{
			tot++;
		
			s[now].nxt[a[i]-'a']=tot;
			s[tot].fa=now;
			s[tot].num=a[i]-'a';
			s[tot].dep=s[now].dep+1;
		}
		now=s[now].nxt[a[i]-'a'];
	}
	s[now].jd=1;
	s[now].b=sum1;
}
queue<int>q;

void getp()
{
	int now=q.front();
	q.pop();
	int fa=s[now].fa;
	if(fa==0)
	{
		s[now].p=0;
		
	}
	else
	{
		while(s[fa].p!=-1&&!s[s[fa].p].nxt[s[now].num])fa=s[fa].p;
		s[now].p=s[s[fa].p].nxt[s[now].num];
	}
	for(int i = 0; i < 26; i++ )
	{
		if(s[now].nxt[i])
		{
			q.push(s[now].nxt[i]);
		}
	}
//	cout<<"    "<<now<<" "<<s[now].fa<<" "<<s[now].p<<" "<<s[fa].p<<endl;
}
int qz1[2500006],qz2[2500006];int ll,rr;
int g[2500006];
bool checkk(int l, int r, int q)
{
	
//	cout<<ll<<" "<<rr<<" "<<l<<" "<<r<<" "<<q<<" "<<qz2[r]<<" "<<qz2[l-1]*pow(m1,r-l+1)<<endl;
	if(ll<l||rr>r)return 0;
	if(l!=0)
	return( ((qz2[r]-qz2[l-1]*g[r-l+1])%mod1+mod1)%mod1==q);
	else
	return( qz2[r]==q);
}
int ans=0;

void query()
{
	int now=0;
	for(int i= 0; i < a.size(); i++ )
	{
		while(s[now].p!=-1&&s[now].nxt[a[i]-'a']==0)
		{
			now=s[now].p;
		}
		if(s[now].nxt[a[i]-'a']!=0)
		{
			now=s[now].nxt[a[i]-'a'];
			if(s[s[now].p].jd)
			{
//				cout<<now<<" "<<s[now].p<<" "<<i-s[s[now].p].dep+1<<" "<<i<<" "<<s[s[now].p].b<<endl;;
				int kkk=now;
				while(kkk!=-1)
				{
					if(checkk(i-s[s[kkk].p].dep+1,i,s[s[kkk].p].b))
					{
						ans++;
					}
					kkk=s[kkk].p;
				}
				
//				cout<<"END"<<endl;
			}
		}
		else
		now=0;
		
//		cout<<now<<" "<<s[now].nxt[0]<<endl;
	}
	if(s[now].jd)
	{
		if(checkk(a.size()-s[now].dep,a.size()-1,s[now].b))
		{
			ans++;
		}
		
	}
}

void init()
{
	int sum1=0,sum2=0;
	ll=rr=-1;
	
	for(int i=0; i < a.size(); i++ )
	{
		if(ll==-1&&a[i]!=b[i])ll=i;
		if(a[i]!=b[i])rr=i;
		sum1*=m1;
		sum1%=mod1;
		sum1+=(a[i]-'a'+1);
		sum1%=mod1;
		qz1[i]=sum1;
		sum2*=m1;
		sum2%=mod1;
		sum2+=(b[i]-'a'+1);
		sum2%=mod1;
		qz2[i]=sum2;
	}
	
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,qq;
	cin>>n>>qq;
	for(int i= 1;i<=n;i++)
	{
		cin>>a>>b;
//		if(i!=1)
		insert();
		
	}
	g[0]=1;
	for(int i= 1; i <=2500000; i++ )
	{
		g[i]=g[i-1]*m1;
		g[i]%=mod1;
	}
	s[0].p=-1;
	for(int i = 0; i < 26; i++ )
	{
		if(s[0].nxt[i])
		{
			q.push(s[0].nxt[i]);
		}
	}
	while(!q.empty())getp();
//	dfs(0);
	for(int i= 1; i <= qq; i++ )
	{
		cin>>a>>b;
		init();
		ans=0;
		query();
		cout<<ans<<endl;
	}
	
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

