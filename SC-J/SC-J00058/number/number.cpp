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
const int N=1e6+12;
int b[15],n;
char s[N];
signed main()
{
//	cin.tie(0)->sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	n=strlen(s+1);
	rep(i,1,n)
		if(s[i]>='0'&&s[i]<='9')b[s[i]-'0']++;
	per(i,9,0)
		rep(j,1,b[i])cout<<i;
	return 0;
}