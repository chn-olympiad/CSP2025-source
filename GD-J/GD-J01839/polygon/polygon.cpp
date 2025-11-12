#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx=-1,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int sum=0,l,r;
			for(int k=l;k<=r;k++)
			{
				maxx=max(maxx,a[k]);
				sum+=a[k];
			}
			if(sum>maxx*2) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
