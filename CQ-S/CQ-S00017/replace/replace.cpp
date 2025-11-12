#include<bits/stdc++.h>
#define int unsigned long long
#define N 5000010
#define p 998244353
using namespace std;

int h3[N],h4[N],f[N],sz[N],p1[N],p2[N];
map <int,int> h1[N],h2[N];

int get(int op,int k,int l,int r)
{
	if(op==1) return h1[k][r]-h1[k][l-1]*f[r-l+1];
	if(op==2) return h2[k][r]-h2[k][l-1]*f[r-l+1];
	if(op==3) return h3[r]-h3[l-1]*f[r-l+1];
	return h4[r]-h4[l-1]*f[r-l+1];
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	f[0]=1;
	for(int i=1;i<N;i++) f[i]=f[i-1]*p;
	for(int i=1;i<=n;i++) 
	{
		string s1,s2;
		cin>>s1>>s2;
		sz[i]=s1.size();
		s1=" "+s1,s2=" "+s2;
		h1[i][0]=h2[i][0]=1;
		for(int j=1;j<=sz[i];j++) h1[i][j]=h1[i][j-1]*p+s1[j],h2[i][j]=h2[i][j-1]*p+s2[j];
		for(p1[i]=1;p1[i]<=sz[i];p1[i]++) if(s1[p1[i]]!=s2[p1[i]]) break;
		for(p2[i]=sz[i];p2[i]>=1;p2[i]--) if(s1[p2[i]]!=s2[p2[i]]) break;
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int sz1=s1.size(),sz2=s2.size(),ans=0;
		if(sz1!=sz2)
		{
			cout<<0<<endl;
			continue;
		}
		s1=" "+s1,s2=" "+s2;
		h3[0]=h4[0]=1;
		for(int i=1;i<=sz1;i++) h3[i]=h3[i-1]*p+s1[i];
		for(int i=1;i<=sz2;i++) h4[i]=h4[i-1]*p+s2[i];
		int l=1,r=sz1;
		for(;l<=sz1;l++) if(s1[l]!=s2[l]) break;
		for(;r>=1;r--) if(s1[r]!=s2[r]) break;
		for(int i=1;i<=n;i++)
		{
			if(l-p1[i]+1>=1&&r+sz[i]-p2[i]<=sz1&&get(3,0,l,r)==get(1,i,p1[i],p2[i])&&get(4,0,l,r)==get(2,i,p1[i],p2[i])&&get(1,i,1,p1[i]-1)==get(3,0,l-p1[i]+1,l-1)&&get(1,i,p2[i]+1,sz[i])==get(3,0,r+1,r+sz[i]-p2[i])&&get(2,i,1,p1[i]-1)==get(4,0,l-p1[i]+1,l-1)&&get(2,i,p2[i]+1,sz[i])==get(4,0,r+1,r+sz[i]-p2[i])) ans++;
		}
		cout<<ans<<endl;
	}
}
