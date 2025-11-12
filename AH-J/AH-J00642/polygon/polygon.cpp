#include<bits/stdc++.h>
using namespace std;
int ans,cnt;
int n,m,k;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("poltgon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=i;j<=n;j++)
		{
			ans+=a[j];
			k=ans-a[j]*2;
			for(int l=1;l<=n;l++)
				if(k>=a[l])
					cnt++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
//16:00~20:00 4h
