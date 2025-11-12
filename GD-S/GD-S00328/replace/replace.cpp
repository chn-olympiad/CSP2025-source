//code by 201012280925LSY
#include<bits/stdc++.h>
using namespace std;
const long long N=1000010;
long long n,q,DP[N],len,answer;
map<string,string>mp;
string x,y;
struct th
{
	string a,b;
}a[N];
bool flag;
long long cnt,tmp,L[N],R[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		L[i]=-1;
		cin>>a[i].a>>a[i].b;
		mp[a[i].a]=a[i].b;
		cnt=tmp=0;
		for(int j=0;j<a[i].a.size();++j)
		{
			if(a[i].a[j]=='a')cnt++;
			else if(a[i].a[j]=='b')tmp++;
		}
		if(tmp!=1||cnt!=a[i].a.size()-1)flag=1;
		cnt=tmp=0;
		for(int j=0;j<a[i].b.size();++j)
		{
			if(a[i].b[j]=='a')cnt++;
			else if(a[i].b[j]=='b')tmp++;
		}
		if(tmp!=1||cnt!=a[i].b.size()-1)flag=1;
		for(int j=0;j<a[i].a.size();++j)
		{
			if(a[i].a[j]=='b')L[i]=j;
			if(a[i].b[j]=='b')R[i]=j;
		}
//		cout<<L[i]<<":"<<R[i]<<"\n";
	}
	if(!flag)
	{
		while(q--)
		{
			cin>>x>>y;
			answer=0;
			x=' '+x,y=' '+y;
			if(x.size()!=y.size())
			{
				cout<<0<<"\n";
				continue;
			}
			int len,l=-1,r;
			len=x.size()-1;
			for(int i=1;i<=len;++i)
			{
				if(x[i]=='b')l=i;
				if(y[i]=='b')r=i;
			}
//			cout<<l<<" "<<r<<"\n";
			for(int i=1;i<=n;++i)
			{
				if(r-l+1==R[i]-L[i]+1&&min(l,r)-1>=min(L[i],R[i])&&len-max(l,r)>=a[i].a.size()-max(L[i],R[i])-1)
				{	
//					cout<<l-1<<":"<<L[i]<<" "<<len-r<<":"<<a[i].a.size()-R[i]-1<<"\n";
					answer++;
				}
			}
			cout<<answer<<"\n";
		}
		return 0;
	}
	
	while(q--)
	{
		answer=0;
		cin>>x>>y;
		x=' '+x,y=' '+y;
		if(x.size()!=y.size())
		{
			cout<<0<<"\n";
			continue;
		}
		int len,l=-1,r;
		len=x.size();
		for(int i=1;i<=len;++i)
		{
			if(x[i]!=y[i]&&l==-1)l=i;
			else if(x[i]!=y[i])r=i;
		}
		string st1,st2,old1="",old2="";
		for(int i=l;i<=r;++i)old1+=x[i],old2+=y[i];
		for(int i=l;i>=1;i--)
		{
			st1=old1,st2=old2;
			for(int j=r;j<=len;++j)
			{
				if(mp[st1]==st2)answer++;
				st1+=x[j+1];
				st2+=y[j+1];
			}
			old1=x[i-1]+old1;
			old2=y[i-1]+old2;
		}
		cout<<answer<<"\n";
	}
	return 0;
}
/*
4 1
ba ab
aba aab
aaab aaba
aabaa aaaba
aabaa
aaaba
*/
