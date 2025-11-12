#include<bits/stdc++.h>
using namespace std;
string a[50005],b[50005];
long long n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int Q=1;Q<=q;Q++)
	{
		long long ans=0;
		string c,d;
		cin>>c>>d;
		for(int i=1;i<=n;i++) 
		{
			for(int j=0;j<=c.size()-1;j++)
			{
				bool flg=1;
				for(int k=0;k<=a[i].size()-1;k++)if(c[j+k-1]!=a[i][k]){
					flg=0;
					break;
				}
				if(flg)
				{
					string pol;
					for(int k=0;k<=c.size()-1;k++)pol+=c[i];
					for(int k=0;k<=a[i].size()-1;k++)pol[j+k-1]=b[i][k];
					flg=1;
					for(int k=0;k<=pol.size()-1;k++)if(pol[k]!=d[k]){
					flg=0;
					break;
					}
				if(flg)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
