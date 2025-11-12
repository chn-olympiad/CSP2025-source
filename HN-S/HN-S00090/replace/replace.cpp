#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,base=196477;
int n,q;
ull hs1[N],hs2[N],hs3[N],hs4[N],pw[N*20],len[N];
map<ull,int> m;
ull get_hs(ull hs[],int l,int r)
{
	return hs[r]-hs[l-1]*pw[r-l+1];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=4000000;i++)
		pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		len[i]=s1.size();
		s1=' '+s1,s2=' '+s2;
		for(int j=1;j<s1.size();j++)
			hs1[i]=hs1[i]*base+s1[j];
		for(int j=1;j<s2.size();j++)
			hs2[i]=hs2[i]*base+s2[j];
		m[hs1[i]]=i;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int p=s1.size(),q=s2.size();
		if(p!=q)
		{
			cout<<"0\n";
			continue;
		}
		s1=' '+s1,s2=' '+s2;
		for(int j=1;j<=q;j++)
		{
			hs3[j]=hs3[j-1]*base+s1[j];
			hs4[j]=hs4[j-1]*base+s2[j];
		}
		int ans=0;
		for(int j=1;j<=q;j++)
			for(int k=1;k<=n;k++)
				if(get_hs(hs3,1,j-1)==get_hs(hs4,1,j-1)
				&&get_hs(hs3,j,j+len[k]-1)==hs1[k]&&
				get_hs(hs4,j,j+len[k]-1)==hs2[k]&&
				get_hs(hs3,j+len[k],q)==get_hs(hs4,j+len[k],q))
					ans++;
		cout<<ans<<"\n";
	}
	return 0;
}

