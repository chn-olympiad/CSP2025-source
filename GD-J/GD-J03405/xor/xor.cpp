#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,b[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=i;j<=n;j++)
		{
			s^=a[j];
			if(s==m)b[i]=j;
		}
		if(b[i]==0)b[i]=n+1;
	}
	for(int i=1;i<=n;i++)
	{
		int t=i,ss=0;
		while(t<n)
		{
			int x=n+1;
			if(t==b[t])ss++;
			for(int j=t+1;j<=n;j++)
				x=min(x,b[j]);
			t=x;
			if(t>n)break;
			ss++;
		}
		ans=max(ss,ans);
	}
	cout<<ans;
	return 0;
}
