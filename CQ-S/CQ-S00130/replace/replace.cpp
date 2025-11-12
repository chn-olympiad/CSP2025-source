#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second

namespace kanade
{
	int read()
	{
		int ans=0,bs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')bs*=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans*bs;
	}
	
	char S[5000010],T[5000010];
	pll pre[5000010][2],nxt[5000010][2];
	
	const ll m1=520091101,m2=1e9+7,b1=233,b2=107;
	
	pll g(char S[],int n)
	{
		ll a=0,b=0;
		for(int i=1;i<=n;i++)
		{
			a=a*b1+S[i]-'a'+1;
			a%=m1;
			b=b*b2+S[i]-'a'+1;
			b%=m2;
		}
		return mkp(a,b);
	}
	
	void  ins(pll &a,char c)
	{
		a.fi=(a.fi*b1+c-'a'+1)%m1;
		a.se=(a.se*b2+c-'a'+1)%m2;
	}
	
	
	struct node
	{
		int len;
		pll a,b;
		
	}A[1000010];
	
	bool cmp(node a,node b)
	{
		return a.len<b.len;
	}
	
	
	int main()
	{
		int n=read(),q=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",S+1);
			A[i].len=strlen(S+1);
			A[i].a=g(S,A[i].len);
			scanf("%s",S+1);
			A[i].b=g(S,A[i].len);
		//	cout<<A[i].a.fi<<' '<<A[i].a.se<<endl;
		}
		sort(A+1,A+1+n,cmp);
		while(q--)
		{
			scanf("%s",S+1);
			scanf("%s",T+1);
			int len=strlen(S+1),len2=strlen(T+1);
			if(len!=len2)
			{
				cout<<"0\n";
				continue;
			}
			pll a=mkp(0,0),b=mkp(0,0);
			for(int i=1;i<=len;i++)
			{
				ins(a,S[i]);
				ins(b,T[i]);
				pre[i][0]=a;
				pre[i][1]=b;
			}
			nxt[len+1][0]=nxt[len+1][1]=a=b=mkp(0,0);
			for(int i=len;i;i--)
			{
				ins(a,S[i]);
				ins(b,T[i]);
				nxt[i][0]=a;
				nxt[i][1]=b;
			}
			ll ans=0;
			for(int i=1;i<=len;i++)
			{
				pll a=mkp(0,0),b=mkp(0,0);
				int w=1;
				for(int j=i;j<=len;j++)
				{
					ins(a,S[j]);
					ins(b,T[j]);
					while(w<=n&&A[w].len==j-i+1)
					{
						if(pre[i-1][0]==pre[i-1][1]&&nxt[j+1][0]==nxt[j+1][1]&&a==A[w].a&&b==A[w].b)ans++;
						w++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		
		return 0;
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	kanade::main();
	return 0;
}

