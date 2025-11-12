//不会每个人只有中间一段可能发生替换吧! 
#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define M 5000005
#define lxl long long
#define INF 1000000000
#define ull unsigned long long
namespace lzz
{
	int n,Q,len;
	ull hash[N];
	char s1[M],s2[M];
	const ull base=73;
	ull b[N]; int o,res[N];
	int L[N],R[N]; ull h1[N],h2[N];
	vector<int>q[N]; unordered_map<ull,bool>mp;
	ull sh[N],inv[N];
	ull get(int l,int r){return sh[r]-sh[l-1]*inv[r-l+1];}
	void build()
	{
		sh[0]=inv[0]=1;
		for(int i=1;i<=len;i++)sh[i]=sh[i-1]*base+(s1[i]-'a'+1),inv[i]=inv[i-1]*base;
	}
	map<pair<ull,ull> ,int>pp; 
	int main()
	{
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n>>Q;
		for(int i=1;i<=n;i++)
		{
			cin>>(s1+1)>>(s2+1),len=strlen(s1+1);
			int x=1,y=len;
			while(x<=len&&s1[x]==s2[x])x++;
			while(y&&s1[y]==s2[y])y--;
			for(int j=x;j<=y;j++)hash[i]=hash[i]*base+(s1[j]-'a'+1);
			for(int j=x;j<=y;j++)hash[i]=hash[i]*base+(s2[j]-'a'+1);
			for(int j=1;j<x;j++)h1[i]=h1[i]*base+(s1[j]-'a'+1);
			for(int j=y+1;j<=len;j++)h2[i]=h2[i]*base+(s1[j]-'a'+1);
			L[i]=x-1,R[i]=len-y,b[++o]=hash[i],mp[hash[i]]=1;
//			cout<<"$$$"<<i<<" "<<hash[i]<<" "<<x<<" "<<y<<endl;
		}
		sort(b+1,b+o+1),o=unique(b+1,b+o+1)-b-1;
		for(int i=1;i<=n;i++)hash[i]=lower_bound(b+1,b+o+1,hash[i])-b,q[hash[i]].push_back(i);
		for(int i=1;i<=Q;i++)
		{
			int ans=0;
			cin>>(s1+1)>>(s2+1),len=strlen(s1+1);
			if((int)strlen(s2+1)!=len){cout<<"0\n"; continue;} build();
			int x=1,y=len; while(x<=len&&s1[x]==s2[x])x++; while(y&&s1[y]==s2[y])y--;
			ull hh=0; for(int j=x;j<=y;j++)hh=hh*base+(s1[j]-'a'+1); for(int j=x;j<=y;j++)hh=hh*base+(s2[j]-'a'+1);
			if(pp.find({sh[len],hh})!=pp.end()){cout<<pp[{sh[len],hh}]<<'\n'; continue;}
			if(!mp[hh]){cout<<"0\n"; continue;} int now=lower_bound(b+1,b+o+1,hh)-b;
//			cout<<"##"<<endl;
			for(int pos:q[now])
			{
//				cout<<"**"<<pos<<endl;
				if(L[pos]>x-1||R[pos]>len-y)continue;
				ull x1=get(x-1-L[pos]+1,x-1),x2=get(y+1,y+1+R[pos]-1);
//				cout<<"##"<<x1<<" "<<x2<<" "<<h1[pos]<<" "<<h2[pos]<<" "<<L[pos]<<" "<<R[pos]<<endl;
				if(x1==h1[pos]&&x2==h2[pos])ans++;
			}cout<<(pp[{sh[len],hh}]=ans)<<'\n';
		}
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}

