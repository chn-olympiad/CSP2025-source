#include<bits/stdc++.h>
using namespace std;
const int base1=131,base2=1331,mod=1e6;
int n,q;
long long hsh1[200010],hsh2[200010];
string s1[200010],s2[200010];
vector<int> vc[2000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int l=s1[i].size();
		for(int j=0;j<=l-1;j++)
		{
			hsh1[i]=(hsh1[i]*base1+s1[i][j]-'a')%mod;
			hsh2[i]=(hsh2[i]*base1+s2[i][j]-'a')%mod;
		}
		int ll,rr;
		for(ll=0;ll<=l-1;ll++)
			if(s1[i][ll]!=s2[i][ll])break;
		for(rr=l-1;rr>=0;rr--)
			if(s1[i][rr]!=s2[i][rr])break;
		if(ll>rr)continue;
		int h1=0,h2=0;
		for(int j=ll;j<=rr;j++)
		{
			h1=(h1*base1+s1[i][j]-'a')%mod;
			h2=(h2*base2+s1[i][j]-'a')%mod;
		}
		int th1=0,th2=0;
		for(int j=ll;j<=rr;j++)
		{
			th1=(th1*base1+s2[i][j]-'a')%mod;
			th2=(th2*base2+s2[i][j]-'a')%mod;
		}
		vc[h1^h2^th1^th2^(rr-ll+1)^(h1+h2)].push_back(i);
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			printf("%d\n",0);
			continue;
		}
		int l=t1.size();
		int ll,rr;
		for(ll=0;ll<=l-1;ll++)
			if(t1[ll]!=t2[ll])break;
		for(rr=l-1;rr>=0;rr--)
			if(t1[rr]!=t2[rr])break;
		long long h1=0,h2=0;
		for(int j=ll;j<=rr;j++)
		{
			h1=(h1*base1+t1[j]-'a')%mod;
			h2=(h2*base2+t1[j]-'a')%mod;
		}
		long long th1=0,th2=0;
		for(int j=ll;j<=rr;j++)
		{
			th1=(th1*base1+t2[j]-'a')%mod;
			th2=(th2*base2+t2[j]-'a')%mod;
		}
		printf("%d\n",vc[h1^h2^th1^th2^(rr-ll+1)^(h1+h2)].size());
	}
	return 0;
}
