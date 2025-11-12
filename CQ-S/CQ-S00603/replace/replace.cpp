#include<bits/stdc++.h>
using namespace std;
string a[200005];
string b[200005];
string l,r;
int c[200005]; 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]!=b[i][j])c[i]++;
		}
	}
	while(q--)
	{
		cin>>l>>r;
		int cnt=0;
		int L=-1,R=-1;
		for(int i=0;i<l.size();i++)
		{
			if(l[i]!=r[i])
			{
				cnt++;
				if(L==-1)L=R=i;
				else R=i;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt!=c[i])continue;
			//cout<<i<<'\n';
			for(int j=max(0,R-(int)a[i].size()+1);j+a[i].size()-1<l.size()&&j<=L;j++)
			{
				bool d=1;
				for(int l1=j,l2=0;l2<a[i].size();l1++,l2++)
				{
					if(l[l1]!=a[i][l2]||r[l1]!=b[i][l2])
					{
						d=0;
						break;
					}
				}
				//cout<<j<<' '<<d<<'\n'; 
				if(d==1)
				{
					ans++;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
