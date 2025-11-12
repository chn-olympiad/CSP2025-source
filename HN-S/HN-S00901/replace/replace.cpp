#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,base=13331;
string s1[N],s2[N];
unsigned long long hs1[N],pw[N],hs2[N];
unsigned long long F1(int l,int r)
{
	return hs1[r]-hs1[l]*pw[r-l+1];
}
unsigned long long F2(int l,int r)
{
	return hs2[r]-hs2[l]*pw[r-l+1];
}
map<string,int>m1;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int w=1;w<=n;++w)
	{
		string a,b;
		cin>>a>>b;
		int m=a.size();
		a=" "+a;
		b=" "+b;
		pw[0]=1;
		for (int i=1;i<=m;++i)
			hs1[i]=(hs1[i-1]*base)+(a[i]-'a'+1),
			hs2[i]=(hs2[i-1]*base)+(b[i]-'a'+1),
			pw[i]=pw[i-1]*base;
		string t="";
		//cout<<w<<"\n";
		for (int i=1;i<=m;++i)
		{
			if (a[i]==b[i])
				continue;
			for (int j=i;j<=m;++j)
			{
				//cout<<i<<" "<<j<<" "<<F1(i,j)<<" "<<F2(i,j)<<"\n";
				if (F1(i,j)==F2(i,j))
					continue;
				//cout<<a[j]<<" "<<b[j]<<"\n" ;
				if (a[j]==b[j])
				{
					s1[w]=a.substr(i,j-1-i+1);
					s2[w]=b.substr(i,j-1-i+1);
					break;
				}
			}
			if (!s1[w].size())
			{
				s1[w]=a.substr(i,m-i+1);
				s2[w]=b.substr(i,m-i+1);
			}
			break;
		}
		//cout<<s1[w]<<" "<<s2[w]<<"\n\n"; 
	}
	for (;q--;)
	{
		string a,b;
		cin>>a>>b;
		int m=a.size();
		a=" "+a;
		b=" "+b;
		pw[0]=1;
		for (int i=1;i<=m;++i)
			hs1[i]=(hs1[i-1]*base)+(a[i]-'a'+1),
			hs2[i]=(hs2[i-1]*base)+(b[i]-'a'+1),
			pw[i]=pw[i-1]*base;
		string t="",s="";
		for (int i=1;i<=m;++i)
		{
			if (a[i]==b[i])
				continue;
			for (int j=i;j<=m;++j)
			{
				if (F1(i,j)==F2(i,j))
					continue;
				if (a[j]==b[j])
				{
					t=a.substr(i,j-1-i+1);
					s=b.substr(i,j-1-i+1);
					break;
				}
			}
			if (!s.size())
			{
				t=a.substr(i,m-i+1);
				s=b.substr(i,m-i+1);
			}
			break;
		}
		//cout<<t<<" "<<s<<" "<<q<<"\n";
		int ans=0;
		for (int i=1;i<=n;++i)
			if (s1[i]==t&&s2[i]==s)
				++ans;//cout<<i<<"\n";
		cout<<ans<<"\n"; 
	}
	return 0;
}
