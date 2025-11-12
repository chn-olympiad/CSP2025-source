#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,q;
int si[maxn],ti[maxn];
string s[maxn][2],t[maxn][2];
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
bool check(int id1,int x,int id2,bool f)
{
	if(si[id2]>ti[id1]) return false;
	for(int i=0;i<si[id2];i++) if(t[id1][f][i+x]!=s[id2][f][i]) return false;
	return true;
}
bool check2(int id,int l,int r)
{
	for(int i=0;i<l;i++) if(t[id][0][i]!=t[id][1][i]) return false;
	for(int i=r+1;i<ti[id];i++) if(t[id][0][i]!=t[id][1][i]) return false;
	return true;
}
void inpu()
{
	n=read(),q=read();
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
}
void deal()
{
	for(int i=1;i<=q;i++) ti[i]=t[i][0].size();
	for(int i=1;i<=n;i++) si[i]=s[i][0].size();
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int p=0;p<=ti[i]-si[j];p++) if(check(i,p,j,0)&&check(i,p,j,1))
			{
		//		cout<<"j2="<<j<<'\n';
				if(check2(i,p,p+si[j]-1))
				{
					ans++;
	//				cout<<"j="<<j<<'\n';
				}
			}
		}
		printf("%d\n",ans);
	}
}
void solve()
{
	inpu();
	deal();
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int test=1;
	while(test--) solve();
	return 0;
}