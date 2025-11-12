#include<bits/stdc++.h>
using namespace std;
//define int long long
char ibuf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++) 
#define per(i,r,l) for(int i=r;i>=l;i--)
#define endl '\n'
inline void read(int &x)
{
	x=0;int f=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x*=f;
}

//
const int N=5e5+12;
int a[N],s[N],f[N],k,n,ans;
map<int,int>mp;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);read(k);
	rep(i,1,n)read(a[i]),s[i]=a[i]^s[i-1];
	mp[0]=0;
	rep(i,1,n)
	{
		f[i]=f[i-1];
		int t=k^s[i];
		if(mp.find(t)!=mp.end())f[i]=max(f[i],mp[t]+1);
		mp[s[i]]=max(mp[s[i]],f[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}