#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[5000010][2],b[5000010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		long long sum=0;
		cin>>b[i][0]>>b[i][1];
		for(int j=1;j<=n;j++)
		{
			long long tp=b[i][0].find(a[j][0]);
			if(tp==-1) continue;
			string tmp=b[i][0];
			for(int k=tp;k<tp+(long long)(a[j][0].size());k++)
			{
				tmp[k]=a[j][1][k-tp];
			}
			if(tmp==b[i][1])
			{
				sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
