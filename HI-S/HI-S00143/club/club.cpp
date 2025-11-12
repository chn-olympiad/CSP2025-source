#include <bits/stdc++.h>
using namespace std;
int a,b,c,sum[1001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int t;
			cin>>a>>b>>c;
			t+=max(max(a,b),max(b,c));
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<sum[i]<<endl;
	}
    return 0;
}


