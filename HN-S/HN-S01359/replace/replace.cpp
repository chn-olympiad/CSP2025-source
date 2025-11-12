#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int L=1e7;
const int N=4e5+100;


struct lige
{
	int nx;
	string qstr;
	string rstr;
	string tostr;
	int qlen,rlen;
	lige()
	{
		nx=-1;
		qstr="";
		rstr="";
		tostr="";
		qlen=0;
		rlen=0;
	}
}e[N];

int eid;

struct Trie
{
	char now;
	int nx;
	int son;
	int h;
	Trie()
	{
		now='\0';
		nx=-1;
		son=-1;
		h=-1;
	}
}T[L];

string str;
int Tend;
int Tid=0;
int insert(int now,int w)
{
	if(w==Tend)
	{
		return now;
	}
	if(T[now].son==-1)
	{
		Tid++;
		T[now].son=Tid;
		T[Tid].now=str[w];
	}
	for(int i=T[now].son;;)
	{
		if(T[i].now==str[w])
		{
			w++;
			now=i;
			if(w==Tend)
			{
				return now;
			}
			if(T[now].son==-1)
			{
				Tid++;
				T[now].son=Tid;
				T[Tid].now=str[w];
			}
			i=T[now].son;
			continue;
		}
		if(T[i].nx==-1)
		{
			Tid++;
			T[i].nx=Tid;
			T[Tid].now=str[w];
		}
		i=T[i].nx;
	}
}

int find(int now,int w)
{
	if(w==Tend)
	{
		return T[now].h;
	}
	if(T[now].son==-1)
	{
		return -1;
	}
	for(int i=T[now].son;i!=-1;)
	{
		if(T[i].now==str[w])
		{
			now=i;
			w++;
			if(w==Tend)
			{
				return T[now].h;
			}
			if(T[now].son==-1)
			{
				return -1;
			}
			i=T[now].son;
		}
		i=T[i].nx;
	}
	return -1;
}

string a,b;
string to;


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		int len=a.length();
		int l;
		int r;
		for(int i=0;i<len;i++)
		{
			if(a[i]!=b[i])
			{
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--)
		{
			if(a[i]!=b[i])
			{
				r=i;
				break;
			}
		}
		str="";
		for(int i=l;i<=r;i++)
		str+=a[i];
		Tend=r-l+1;
		
		int tmp=insert(0,0);
		
		eid++;
		e[eid].nx=T[tmp].h;
		
		
		for(int i=0;i<l;i++)
		e[eid].qstr+=a[i];
		e[eid].qlen=l;
		for(int i=r+1;i<len;i++)
		e[eid].rstr+=a[i];
		e[eid].rlen=len-r-1;
		for(int i=l;i<=r;i++)
		e[eid].tostr+=b[i];
		
		T[tmp].h=eid;
	}
	
	
	
	
	for(int i=1;i<=q;i++)
	{
		cin>>a;
		cin>>b;
		int len=a.length();
		int len2=b.length();
		if(len!=len2)
		{
			cout<<0<<endl;
			continue;
		}
		int l;
		int r;
		for(int i=0;i<len;i++)
		{
			if(a[i]!=b[i])
			{
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--)
		{
			if(a[i]!=b[i])
			{
				r=i;
				break;
			}
		}
		str="";
		for(int i=l;i<=r;i++)
		str+=a[i];
		Tend=r-l+1;
		to="";
		for(int i=l;i<=r;i++)
		to+=b[i];
		
		int tmp=find(0,0);
		
		long long ans=0;
		if(tmp==-1)
		cout<<0<<endl;
		else
		{
			for(int i=tmp;i!=-1;i=e[i].nx)
			{
				if(e[i].qlen>l)
				continue;
				if(e[i].rlen>len-r-1)
				continue;
				if(a.compare(l-e[i].qlen,e[i].qlen,e[i].qstr)!=0)
				continue;
				if(a.compare(r+1,e[i].rlen,e[i].rstr)!=0)
				continue;
				if(to.compare(e[i].tostr)!=0)
				continue;
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
