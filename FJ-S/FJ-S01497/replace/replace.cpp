#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n,q,ans;
string s1[200005],s2[200005];
ull hs1[200005],hs2[200005];
ull h1[5000005],h2[5000005];
ull p[5000005];
//int wz1[200005],wz2[200005];
ull hlr1(int l,int r)
{
	return (ull)h1[r]-h1[l-1]*p[r-l+1];
}
ull hlr2(int l,int r)
{
	return (ull)h2[r]-h2[l-1]*p[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	p[0]=1;
	for(int i =1;i<=5e6;i++)
	{
		p[i]=p[i-1]*233;
	}
	for(int i =1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for(int j =0;j<s1[i].size();j++)
		{
//			if(s1[i][j]=='b') wz1[i]=j;
			hs1[i]=hs1[i]*233+s1[i][j]-'a'+1;
		}
		for(int j =0;j<s2[i].size();j++)
		{
//			if(s2[i][j]=='b') wz2[i]=j;
			hs2[i]=hs2[i]*233+s2[i][j]-'a'+1;
		}
//		cout<<hs1[i]<<' '<<hs2[i]<<'\n';
	}
	while(q--)
	{
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		t1=' '+t1;
		t2=' '+t2;
		int L=0,R=0;
		for(int i =1;i<=len;i++)
		{
			if(t1[i]!=t2[i]&&!L) L=i;
			if(t1[i]!=t2[i]) R=i;
		}
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int i =1;i<=len;i++)
		{
			h1[i]=h1[i-1]*233+t1[i]-'a'+1;
			h2[i]=h2[i-1]*233+t2[i]-'a'+1;
		}
//		if(t1[L]=='b'||t2[R]=='b'||t1[R]=='b'||t2[L]=='b')
//		{
//			for(int i =1;i<=n;i++)
//			{
//				int j;
//				if(t1[L]=='b')j=L-wz1[i]+1;
//				else j=R-wz1[i]+1;
//				if(j<1||j+s1[i].size()-1>len) continue;
//				if(hlr1(j,j+s1[i].size()-1)==hs1[i]&&
//				hlr2(j,j+s1[i].size()-1)==hs2[i]&&
//				hlr1(j+s1[i].size(),len)==hlr2(j+s1[i].size(),len))
//				{
//					ans++;
//				}
//			}
//			cout<<ans<<'\n';
//			continue;
//		}
		for(int i =1;i<=n;i++)
		{
			if(R-L+1>s1[i].size()) continue;
			int k =max(1,R-(int)s1[i].size()-1);
			for(int j =k;j<=L&&j+s1[i].size()-1<=len;j++)
			{
//				cout<<hlr1(j,j+s1[i].size()-1)<<'\n';
				if(hlr1(j,j+s1[i].size()-1)==hs1[i]&&
				hlr2(j,j+s1[i].size()-1)==hs2[i]&&
				hlr1(j+s1[i].size(),len)==hlr2(j+s1[i].size(),len))
				{
					ans++;
//					break;
				}
				if(t1[j]!=t2[j]) break;
			}
		}
		cout<<ans<<'\n';
//		while(1)
//		{
//			int l,r;
//			cin>>l>>r;
//			cout<<hlr1(l,r)<<'\n';
//		}
	}
	return 0;
}
