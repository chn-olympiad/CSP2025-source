#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[100005],b[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string s,sp,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<s.size()-a[j].size()+1;k++)
			{
				sp=s;
				int l=0;
				for(;l<a[j].size();l++)
				{
					if(sp[k+l]!=a[j][l])
					{
						l=a[j].size()+3;
						break;
					}
					sp[k+l]=b[j][l];
				}
//				cout<<j<<" "<<k<<" "<<sp<<endl;
				if(sp==t&&l!=a[j].size()+3) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
