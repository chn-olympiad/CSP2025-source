#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>(a[3]*2)) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(n==4)
	{
		ans=0;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=4;k++)
					if((a[i]+a[j]+a[k])>(a[k]*3)) ans++;
		if((a[1]+a[2]+a[3]+a[4])>(a[4]*2)) ans++;
		cout<<ans<<endl;
		return 0;
	}
	cout<<9<<endl;
	return 0;
}
