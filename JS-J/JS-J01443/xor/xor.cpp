#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans[500005]={};
	cin>>n>>k;
	int ooo=0;
	cin>>ans[1];
	for(int i=2;i<=n;++i)
	{
		cin>>ans[i];
		if(ans[i]!=ans[i-1]&&ans[i-1]!=-1)
		{
			ooo++;
			ans[i-1]=-1;
			ans[i]=-1;
		}
			
	}
	if(k==0)cout<<n;
	else if(k==1)
	{
		
		cout<<ooo;
	}
	return 0;
}
