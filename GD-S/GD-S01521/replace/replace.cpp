#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
using ll=long long;
using ull=unsigned ll;
constexpr int N=2e5,M=5e6,B=99997;
int n,q;
string s[N+5][2];
ull h[N+5][2];
ull hs1[M+5];
ull hs2[M+5];
ull pw[M+5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	fr(i,1,M) pw[i]=pw[i-1]*B;
	scanf("%d%d",&n,&q);
	fr(i,1,n)
	{
		cin>>s[i][0]>>s[i][1];
		fr(j,0,(int)s[i][0].length()-1) h[i][0]=h[i][0]*B+s[i][0][j];
		fr(j,0,(int)s[i][1].length()-1) h[i][1]=h[i][1]*B+s[i][1][j];
	}
	fr(i,1,q)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0,p;
		fr(j,0,(int)t1.length()-1) hs1[j+1]=hs1[j]*B+t1[j];
		fr(j,0,(int)t2.length()-1) hs2[j+1]=hs2[j]*B+t2[j];
		fd(j,(int)t1.length()-1,0) if(t1[j]!=t2[j]) {p=j;break;}
		fr(j,0,(int)t1.length()-1)
		{
			bool f=0;
			fr(k,1,n)
			{
				int len=s[k][0].length();
				if(j+len>t1.length()) continue;
				f=1;
				if(h[k][0]==hs1[j+len]-hs1[j]*pw[len]&&h[k][1]==hs2[j+len]-hs2[j]*pw[len]&&j+len-1>=p) ++ans;
			}
			if(t1[j]!=t2[j]||!f) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}