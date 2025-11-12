#include<bits/stdc++.h>
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define ff(i,a,b) for(int i=(a);i>=(b);i--)
#define sd std::
#define dbg(x) sd cout<<#x<<":"<<x<<" "
#define dg(x) sd cout<<#x<<":"<<x<<"\n"
#define inf 1e10
#define pii sd pair<int,int>
#define X first
#define Y second
int read(){int w=1,c=0;char ch=getchar();for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;for(;ch>='0'&&ch<='9';ch=getchar()) c=(c<<3)+(c<<1)+ch-48;return w*c;}
void printt(int x){if(x>9) printt(x/10);putchar(x%10+48);}
void print(int x){if(x<0) putchar('-'),x=-x;printt(x);}
void printk(int x){print(x);putchar(' ');}
void put(int x){print(x);puts("");}
const int N=5e6+10,P=1e9+9,base=131;
void fre()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int po[N],ha1[N],ha2[N];
int hash1(int l,int r)
{
	return (ha1[r]-ha1[l-1]*po[r-l+1]%P+P)%P;
}
int hash2(int l,int r)
{
	return (ha2[r]-ha2[l-1]*po[r-l+1]%P+P)%P;
}
int n,q,len,len2;
char s1[N],s2[N];
sd map<pii,int> mp;//记录哈希 
void solve()
{
	n=read(),q=read();
	po[0]=1;
	F(i,1,5000000) po[i]=po[i-1]*base%P;
	F(cas,1,n)
	{
		scanf("%s%s",s1+1,s2+1);
		len=strlen(s1+1);
		F(i,1,len)
		{
			ha1[i]=(ha1[i-1]*base%P+s1[i]-'a'+1)%P;
			ha2[i]=(ha2[i-1]*base%P+s2[i]-'a'+1)%P;
		}
		mp[sd make_pair(ha1[len],ha2[len])]++;
	}
	while(q--)
	{
		scanf("%s%s",s1+1,s2+1);
		len=strlen(s1+1),len2=strlen(s2+1);
		if(len!=len2)
		{
			put(0);
			continue;
		}
		F(i,1,len)
		{
			ha1[i]=(ha1[i-1]*base%P+s1[i]-'a'+1)%P;
			ha2[i]=(ha2[i-1]*base%P+s2[i]-'a'+1)%P;
		}
		int ans=0;
		F(i,1,len)
		{
			if(i>1&&s1[i-1]!=s2[i-1]) break;
			ff(j,len,i)
			{
				//i~j
				if(j<len&&s1[j+1]!=s2[j+1]) break;
//				dbg(i),dg(j);
//				dbg(hash1(i,j)),dg(hash2(i,j));
//				dg(mp[sd make_pair(hash1(i,j),hash2(i,j))]);
				ans+=mp[sd make_pair(hash1(i,j),hash2(i,j))];
			}
		}
		put(ans);
	}
}
signed main()
{
	fre();
	int T=1;
//	T=read();
	while(T--) solve();
}
/*
问号
即对于替换一个 [l,r]，合法当且仅当 $t,12$ 的前后缀都相同且中间替换之后是另一个
然后发现好像就是对于二元组 i 求有多少个二元组的 s1,s2都是 i 的前缀
这个字典树即可
然后哈希随便做做？  
先写个暴力吧
为啥调不出来啊，只能写暴力了 
*/
