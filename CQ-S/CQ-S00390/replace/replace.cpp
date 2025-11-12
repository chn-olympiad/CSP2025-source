#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;

const int MAXN=2000+5,B=13,M=1e9+7;
int a1[MAXN],a2[MAXN],b1[MAXN],b2[MAXN],b[MAXN],l[MAXN],cnt[MAXN],n,m;
string s1,s2;

void Hash1(int x,string s,bool o)
{
	ll sum=0;
	for(int i=0;i<s.size();i++) sum=(sum*B%M+s[i])%M;
//	cout<<sum<<" ";
	if(o) a1[x]=sum;
	else a2[x]=sum;
}

void Hash2(string s)
{
	for(int i=0;i<s.size();i++) b1[i+1]=(b1[i]*B%M+s[i])%M;
}

void Hash3(string s)
{
	for(int i=0;i<s.size();i++) b2[i+1]=(b2[i]*B%M+s[i])%M;
}

int query1(int l,int r)
{
	r++;
//	cout<<b1[r]<<" "<<b1[l]<<endl;
	return (b1[r]-b1[l]*b[r-l]%M+M)%M;
}

int query2(int l,int r)
{
	r++;
	return (b2[r]-b2[l]*b[r-l]%M+M)%M;
}

signed main()
{
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	b[0]=1;
	for(int i=1;i<=2000;i++) b[i]=b[i-1]*B%M;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		Hash1(i,s1,1);Hash1(i,s2,0);
		l[i]=s2.size();		
		for(int j=0;j<s1.size();j++) cnt[i]+=(s1[j]!=s2[j]);
//		cout<<endl;																																			
	}
	while(m--)
	{
		cin>>s1>>s2;
		Hash1(n+1,s1,1);
		if(s1.size()!=s2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int cnt1=0;
		for(int i=0;i<s1.size();i++) cnt1+=(s1[i]!=s2[i]);
		Hash2(s1);Hash3(s2);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int len=l[i];
			if(len>1*s1.size() || cnt1!=cnt[i]) continue;
			bool flag=0;
			for(int j=0;j<=s1.size()-len;j++)
			{
				for(int k=0;k<=s1.size()-len;k++)
				{
//					cout<<j<<' '<<j+len-1<<" "<<a1[i]<<" "<<query1(j,j+len-1)<<' '<<a2[i]<<" "<<query2(k,k+len-1)<<endl;
					if(a1[i]==query1(j,j+len-1) && a2[i]==query2(k,k+len-1))
					{
						ans++;
//						cout<<i<<endl;
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
//by Matrix_Power
/*
lg uid:1068500
*/
