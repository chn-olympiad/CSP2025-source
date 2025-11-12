#include<bits/stdc++.h>
#define ull unsigned long long
#define pii pair<ull,ull>
#define fi first
#define se second
using namespace std;

inline int read()
{
	int x=0,fu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}

void write(int x)
{
	if(x<0){putchar('-'),x=-x;}
	if(x<10){putchar(x+'0');return;}
	write(x/10);putchar(x%10+'0');
}

const int N=2e5+10,M=5e6+10;
const ull P=13331;
int n,q;
ull pw[M],sum[M];
char s[N],t[N];
ull H(int l,int r)
{
	return sum[r]-sum[l-1]*pw[r-l+1];
}
map<pii,int>mp;
int tot;
struct node
{
	ull h1,h2;
	int d1,d2;
};
vector<node>vec[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	pw[0]=1;
	for(int i=1;i<M;i++)	pw[i]=pw[i-1]*P;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1),scanf("%s",t+1);
		int le=1;
		while(s[le]==t[le])	le++;
		int len=strlen(s+1);
		int ri=len;
		while(s[ri]==t[ri])	ri--;
		ull h1=0,h2=0,h3=0,h4=0;
		for(int i=1;i<le;i++)	h1=h1*P+s[i];
		for(int i=le;i<=ri;i++)	h2=h2*P+s[i],h3=h3*P+t[i];
		for(int i=ri+1;i<=len;i++)	h4=h4*P+s[i];
//		cout<<h2<<" "<<h3<<endl;
		if(!mp[{h2,h3}])	mp[{h2,h3}]=++tot;
		vec[mp[{h2,h3}]].push_back({h1,h4,le-1,len-ri});
	}
	while(q--)
	{
		scanf("%s",s+1),scanf("%s",t+1);
		int le=1;
		while(s[le]==t[le])	le++;
		int len=strlen(s+1);
		int ri=len;
		while(s[ri]==t[ri])	ri--;
		for(int i=1;i<=len;i++)	sum[i]=sum[i-1]*P+s[i];
		ull h1=0,h2=0,h3=0,h4=0;
		for(int i=1;i<le;i++)	h1=h1*P+s[i];
		for(int i=le;i<=ri;i++)	h2=h2*P+s[i],h3=h3*P+t[i];
		for(int i=ri+1;i<=len;i++)	h4=h4*P+s[i];
//		cout<<h2<<"qwq"<<h3<<endl;
		if(mp.find({h2,h3})==mp.end())
		{
			puts("0");
			continue;
		}
		int ans=0;
		int id=mp[{h2,h3}];
		for(node x:vec[id])
		{
//			cout<<x.h2<<" "<<ri+x.d2<<" "<<H(ri+1,ri+x.d2)<<endl;
			if(le-x.d1<1||H(le-x.d1,le-1)!=x.h1)	continue;
			if(ri+x.d2>len||H(ri+1,ri+x.d2)!=x.h2)	continue;
			ans++;
		}
		write(ans),puts("");
	}
	return 0;
}
