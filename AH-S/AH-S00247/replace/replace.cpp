#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200100],b[200100],x,y;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	cin>>x>>y;
	for(int i=1;i<=n;i++)
	{
		int flag=0,p=0,ka=a[i].size();
		for(int j=0;j<ka;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				if(!flag)
				{
					int kx=x.size();
					for(int k=0;k<kx;k++) a[i][j+k]=y[k];
					j--;
					flag=1;
				}
				else
				{
					p=1;
					break;
				}
			}
		}
		if(p==1) cout<<0;
		else cout<<1;
		cout<<endl;
	}
	return 0;
}
