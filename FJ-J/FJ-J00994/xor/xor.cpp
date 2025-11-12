#include<bits/stdc++.h>
using namespace std;
int n,m,x=0,ans=0,a[500010],ax[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		ax[i]=(ax[i-1]^a[i]);
	}
	for (int i=1;i<=n;++i)
	  for (int j=1;j<=i;++j)
	  {
	  	if((ax[i]^ax[j-1])==m)
	  	{
	  		if(j<=x) continue;
	  		x=i;++ans;
	  		break;
		}
	  }
	cout<<ans<<endl;
	return 0;
}
