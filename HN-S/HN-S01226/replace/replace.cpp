/*
ygg plz!
luogu 1058570(the person who fought with kkksc03.)
plz 350+.

ok let this be t3 code.
oh no is it ACzi_dong_ji???
can't solve...

ok i don't know the problem at first.
the change can't be >1.lol
noooooooo it IS that.
it is easy with ACzi_dong_ji but I CAN'T SOLVE IT.
nooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
anyway next.

(16:57)get POINTS!!!
noo idk how to solve B.........
but AB is ok.likely 30.
then 100+16+30+24=170?btw?
i don't want to AFO........
plz
noooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

(17:25)yessssssssssssssssssssssss!
t2 is 72!!!
now 100+72+30+24=226!
plz let me get this!

i think trie is important in this problem.(2048Mib heyiwei?)
but idk how to solve it.
anyway baoli will help.

(17:43)uhh i have no time to solve AB.
actually just 5pts?
i'll try after solving t4.

solved yangli3 in 159.3s.LOL
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=133,mod=1e14+10299;
//let 010299 help me!this mod will not be hacked.
inline int read()
	{
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
	}//int x=read();
int n,q,hs1[200005],hs2[200005],ht1[5000005],ht2[5000005],mi[5000005];
int get1(int l,int r){return ((ht1[r]-ht1[l-1]*mi[r-l+1])%mod+mod)%mod;}
int get2(int l,int r){return ((ht2[r]-ht2[l-1]*mi[r-l+1])%mod+mod)%mod;}
string s1[200005],s2[200005];
inline void sol()
	{
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;i++)
		{
		for(int j=0;j<s1[i].size();j++)hs1[i]=(hs1[i]*P+(int)s1[i][j])%mod;
		for(int j=0;j<s2[i].size();j++)hs2[i]=(hs2[i]*P+(int)s2[i][j])%mod;
		}
	mi[0]=1;
	for(int i=1;i<=1000000;i++)mi[i]=mi[i-1]*P%mod;
	while(q--)
		{
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		t1=' '+t1;t2=' '+t2;
		for(int i=1;i<t1.size();i++)ht1[i]=(ht1[i-1]*P+(int)t1[i])%mod;
		for(int i=1;i<t2.size();i++)ht2[i]=(ht2[i-1]*P+(int)t2[i])%mod;
		int ans=0;
		for(int i=1;i<t1.size();i++)
			{
			if(get1(1,i-1)!=get2(1,i-1))break;
			for(int j=1;j<=n;j++)
				{
				int m=s1[j].size();
				if(get1(i,i+m-1)==hs1[j])if(get2(i,i+m-1)==hs2[j])if(get1(i+m,t1.size()-1)==get2(i+m,t2.size()-1))ans++;
				}
			}
		cout<<ans<<'\n';
		}
	return;
	}
signed main()
	{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--)sol();
	return 0;
	}

