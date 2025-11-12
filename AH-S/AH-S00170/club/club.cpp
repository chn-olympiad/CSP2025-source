#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200000][10],d[10],ans,b[200000],c[200000];
void bl(long long k,long long s)
{
	if(k==n+1)
	{
		ans=max(ans,s);
	}
	for(int i=1;i<=3;i++)
	{
		if(d[i]<n/2)
		{
			d[i]++;
			bl(k+1,s+a[k][i]);
			d[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int k1=0,k2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			k1+=a[i][2];
			b[i]=a[i][1];
			k2+=a[i][3];
			c[i]=a[i][2];
		}
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		ans=0;
		if(k1==0&&k2==0)
		{
			for(int i=n;i>=n/2+1;i--)
			{
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		bl(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
