//GZ-S00055 贵阳市第三实验中学 刘明远 
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000009
const long long b=37;
int n,q;

struct node{
	long long x,y,siz;
	bool operator > (const node& c) const{
		return siz>c.siz;
	}
};
node hs[200005];

long long hash_(string s)
{
	long long res=s[0]-'a';
	for(int j=1;j<s.size();j++)
		res=(res*b%mod+s[j]-'a')%mod;
	return res;
}

long long qpow(int x)
{
	long long res=1;
	long long a=b;
	for(;x;x>>=1)
	{
		if(x&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}

long long x1[5000065],x2[5000065];
long long sub(int l,int r,long long*x)
{
	if(l>r) return 0;
	return (x[r]-x[l-1]*qpow(r-l+1)%mod+mod)%mod;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2; 
		long long cnt1=hash_(s1),cnt2=hash_(s2);
		long long len=s1.size();
		hs[i]={cnt1,cnt2,len};
	}
	sort(hs+1,hs+n+1,greater<node>());
	string t1,t2;
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		x1[0]=t1[0]-'a';
		int len=t1.size();
		for(int j=1;j<len;j++)
			x1[j]=(x1[j-1]*b%mod+t1[j]-'a')%mod;
		x2[0]=t2[0]-'a';
		for(int j=1;j<len;j++)
			x2[j]=(x2[j-1]*b%mod+t2[j]-'a')%mod;
		long long ans=0;
		for(int j=0;j<len&&(j==0||sub(0,j-1,x1)==sub(0,j-1,x2));j++)
		{
			for(int k=1;k<=n;k++)
			{
				int l=hs[k].siz;
				if(j+l>len) continue;
				if(sub(j+l,len-1,x1)!=sub(j+l,len-1,x2)) break;
				if(sub(j,j+l-1,x1)==hs[k].x&&sub(j,j+l-1,x2)==hs[k].y)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
