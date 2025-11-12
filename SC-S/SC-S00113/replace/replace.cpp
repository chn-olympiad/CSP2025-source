#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=1e5+15,d=131;
int qp[N];
int n,q;
map<ull,ull>mp;
int ll[N],len;
ull k1[N],k2[N];
ull get1(int l,int r)
{
	if(l>r) return 0;
	return k1[r]-k1[l-1]*qp[r-l+1];
}
ull get2(int l,int r)
{
	if(l>r) return 0;
	return k2[r]-k2[l-1]*qp[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	qp[0]=1;
	for(int i=1;i<N-10;i++) qp[i]=qp[i-1]*d;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		ull k1=0,k2=0;
		int l1=a.size(),l2=b.size();
		ll[++len]=l1;
		for(int i=0;i<l1;i++)
		{
			k1=k1*d+(a[i]-'a');
		}
		for(int i=0;i<l2;i++)
		{
			k2=k2*d+(b[i]-'a');
		}
		mp[k1]=k2;
	}
	len=unique(ll+1,ll+1+len)-ll-1;
	for(int i=1;i<=q;i++)
	{
		string a,b;
		int ans=0;
		cin>>a>>b;
		int l1=a.size(),l2=b.size();
		a=" "+a;
		b=" "+b;
		for(int i=1;i<=l1;i++)
		{
			k1[i]=k1[i-1]*d+(a[i]-'a');
		}
		for(int i=1;i<=l2;i++)
		{
			k2[i]=k2[i-1]*d+(b[i]-'a');
		}
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=len;j++)
			{
				if(i+ll[j]-1>l1)continue;
//				cout<<i<<" "<<i+ll[j]-1<<" "<<get2(i,i+ll[j]-1)<<" "<<get1(i,i+ll[j]-1)<<"\n";
				if(get1(1,i-1)==get2(1,i-1)&&get1(i+ll[j],l1)==get2(i+ll[j],l1)&&mp[get1(i,i+ll[j]-1)]==get2(i,i+ll[j]-1))
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
 4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/