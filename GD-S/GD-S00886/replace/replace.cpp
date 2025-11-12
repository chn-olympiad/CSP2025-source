#include<bits/stdc++.h>
using namespace std;
const long long m1=1000000007,m2=998244353,pw1=17,pw2=1331; 
long long n,q,da,a,b,c,d,l1;
string s1,s2,ss1,ss2;

struct h
{
	long long ha1,ha2,sha1,sha2,w1,w2;
}e[2000005],cs;

long long lef(long long x)
{
	long long l=1,r=n,mid=0;
	while(l<r)
	{
		mid=(l+r)/2;
		if(e[mid].sha2<x)l=mid+1;
		if(e[mid].sha2==x)r=mid;
		if(e[mid].sha2>x)r=mid-1;
	}
	return l;
}

long long ref(long long x)
{
	long long l=1,r=n,mid=0;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(e[mid].sha2<x)l=mid+1;
		if(e[mid].sha2==x)l=mid;
		if(e[mid].sha2>x)r=mid-1;
	}
	return l;
}


long long has1(string hs1,string hs2)
{
	long long hz=0;
	for(int i=0;i<hs1.size();i++)
	{
		hz=hz*pw1+hs1[i];
		hz%=m1; 
	}
	for(int i=0;i<hs2.size();i++)
	{
		hz=hz*pw1+hs2[i];
		hz%=m1;
	}
	return hz;
}

long long has2(string hs1,string hs2)
{
	long long hz=0;
	for(int i=0;i<hs1.size();i++)
	{
		hz=hz*pw2+hs1[i];
		hz%=m2; 
	}
	for(int i=0;i<hs2.size();i++)
	{
		hz=hz*pw2+hs2[i];
		hz%=m2;
	}
	return hz;
}
bool cmpp(h x,h y)
{
	return x.sha2<y.sha2;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		a=-1,b=0;
		for(int j=0;j<s1.size();j++)
		{
			if(s1[j]!=s2[j])b=j;
			if(s1[j]!=s2[j]&&a==-1)a=j;
		}
		if(a==-1)
		{
			continue;
		}
		e[i].ha1=has1(s1,s2);
		e[i].ha2=has2(s1,s2);
		e[i].sha1=has1(s1.substr(a,(b-a+1)),s2.substr(a,(b-a+1)));
		e[i].sha2=has2(s1.substr(a,(b-a+1)),s2.substr(a,(b-a+1)));
		e[i].w1=a,e[i].w2=s1.size()-1-b;
	}
	sort(e+1,e+1+n,cmpp); 
	for(int i=1;i<=q;i++) 
	{
		cin>>ss1>>ss2;l1=ss1.size();
		if(l1!=ss2.size())
		{
			cout<<0<<endl;
			continue;
		}
		a=-1,b=0;
		for(int j=0;j<l1;j++)
		{
			if(ss1[j]!=ss2[j])b=j;
			if(ss1[j]!=ss2[j]&&a==-1)a=j;
		}
		cs.sha1=has1(ss1.substr(a,(b-a+1)),ss2.substr(a,(b-a+1)));
		cs.sha2=has2(ss1.substr(a,(b-a+1)),ss2.substr(a,(b-a+1)));
		c=lef(cs.sha2);
		d=ref(cs.sha2);
		da=0;
		for(int j=1;j<=n;j++)
		{
			if(cs.sha1==e[j].sha1&&cs.sha2==e[j].sha2)
			{
				if(a-e[j].w1>=0&&l1>=b-a+e[j].w1+e[j].w2+1+a-e[j].w1)
				if(has1(ss1.substr(a-e[j].w1,b-a+e[j].w1+e[j].w2+1),ss2.substr(a-e[j].w1,b-a+1+e[j].w1+e[j].w2))==e[j].ha1
				&& has2(ss1.substr(a-e[j].w1,b-a+e[j].w1+e[j].w2+1),ss2.substr(a-e[j].w1,b-a+1+e[j].w1+e[j].w2))==e[j].ha2)
				da++;
			}
		}
		cout<<da<<endl;
	}
	return 0; 
}
