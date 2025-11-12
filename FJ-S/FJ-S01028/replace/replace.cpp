#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
#define pb push_back
using namespace std;
int read()
{
	int ret=0,sgn=0,ch=getchar();
	while(!isdigit(ch)) sgn|=ch=='-',ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn ? -ret:ret;
}
int n,q;
string s1[MAXN],s2[MAXN];
void solve()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		string t1,t2,f;
		cin>>t1>>t2;
		int N=t1.size();
		for (int i=0;i<N;i++)
		{
			for (int j=1;j<=n;j++)
			{
				int g=s1[j].size();
				if (N-i>=g&&t1.substr(i,g)==s1[j])
				{
					string s=f+s2[j]+t1.substr(i+g);
					ans+=s==t2;
				}
			}
			if (t1[i]!=t2[i]) break;
			f+=t1[i];
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	for (int i=1;i<=T;i++) solve();
	return 0;
}
