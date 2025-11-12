#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
map<pair<string,string>,int>f;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;cin>>a>>b;
		f[make_pair(a,b)]++;
	}
	while(q--)
	{
		string a,b,s,t;cin>>a>>b,s=t="";
		int sum=0;
		int k=(int)(a.size())-1;
		for(;k>0;k--)
			if(a[k]!=b[k])break;
		for(int i=0;i<a.size();i++)
		{
			string te="",tt="";
			for(int j=i;j<a.size();j++)
			{
				te+=a[j],tt+=b[j];
				if(j>=k)
					sum+=f[make_pair(te,tt)];
			}
			if(a[i]!=b[i])break;
		}
		cout<<sum<<"\n";
	}
	return 0;
}

