#include<bits/stdc++.h>
#define s1 s1111
#define s2 s2222
#define t1 t1111
#define t2 t2222
using namespace std;
const int MAXN=100005;
typedef unsigned long long ll;
struct Node
{
	string s1,s2;
};
int n,q;
ll x,y,power[MAXN],h1[MAXN],h2[MAXN];
map<int,int> mp;
string s1,s2,t1,t2;
vector<Node> vec;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
//void init()
//{
//	power[0]=1;
//	for(int i=1;i<=MAXN-1;i++)
//	{
//		power[i]=power[i-1]*131;
//	}
//	return ;
//}
//ll has(string s)
//{
//	int ls=s.size();
//	ll ans=0;
//	for(int i=0;i<=ls-1;i++)
//	{
//		ans=ans*131+s[i];
//	}
//	return ans;
//}
void work()
{
	int ans=0;
	cin>>t1>>t2;
	int l1=t1.size(),l2=t2.size();
	t1=" "+t1,t2=" "+t2;
	string s="",t="",k="";
	for(int i=0;i<=n-1;i++)
	{
		s=vec[i].s1,t=vec[i].s2;
		k=t1;
		int pos=k.find(s,0),len=s.size();
		if(pos!=-1)
		{
			k.erase(pos,len);
			k.insert(pos,t);
			if(k==t2)
			{
				++ans;
			}
		}
	}
	printf("%d\n",ans);
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		vec.push_back({s1,s2});
	}
	if(q<=1000)
	for(int i=1;i<=q;i++)
	{
		work();
	}
	else 
	{
		for(int i=1;i<=q;i++)
		{
			printf("0\n");
		}
	}
	return 0;
}
