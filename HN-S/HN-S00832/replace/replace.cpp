#include<bits/stdc++.h>
using namespace std;
const int p=131;
size_t s[1000005],ksm[1000005],ss[1000005],la[1000005],lb[1000005],ls[1000005];
int n,q;
__inline size_t find(int x,int y)
{
	return s[y]-s[x-1]*ksm[y-x+1]; 
}
__inline size_t finds(int x,int y)
{
	return ss[y]-ss[x-1]*ksm[y-x+1]; 
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>q;
	ksm[0]=1;
	for(int i=1;i<=1000002;++i)
		ksm[i]=ksm[i-1]*p;
	for(int i=1;i<=n;++i)
	{
		string a,b;
		cin>>a>>b;
		a=' '+a;
		b=' '+b;
		size_t k=0,kk=0;
		for(int j=1;j<a.size();++j)
			k=k*p+a[j]-'a'+1;
		for(int j=1;j<b.size();++j)
			kk=kk*p+b[j]-'a'+1;
		la[i]=k;
		lb[i]=kk;
		ls[i]=a.size()-1;
//		cout<<la[i]<<" "<<lb[i]<<"\n";
	}
	while(q--)
	{
		string a,b;
		int ans=0;
		cin>>a>>b;
		a=' '+a; 
		b=' '+b;
		for(int j=1;j<a.size();++j)
			s[j]=s[j-1]*p+a[j]-'a'+1;
		for(int j=1;j<b.size();++j)
			ss[j]=ss[j-1]*p+b[j]-'a'+1;
		for(int i=1;i<a.size();++i)
		{
			if(i!=1)
				if(find(1,i-1)!=finds(1,i-1))
					continue;
			for(int j=1;j<=n;++j)
			{
				int r=i+ls[j]-1;//±íÊ¾Ìæ»»l,r
				if(r>a.size()-1)
					continue;
				if(find(i,r)!=la[j])
					continue;
				if(lb[j]!=finds(i,r))
					continue;
				if(r!=a.size()-1)
					if(find(r+1,a.size()-1)!=finds(r+1,a.size()-1)) 
						continue;
				ans++;
//				cout<<i<<" "<<r<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
