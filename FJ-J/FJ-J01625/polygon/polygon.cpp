#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long n,a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long sum=0,mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(sum>mx*2)
		{
			cout<<1;
		}else{
			cout<<0;
		}
	}else {
		long long su=0;
		for(int i=1;i<=n-2;i++)
		{
			for(int j=n-1-i;j>=1;j--)
			{
				su+=j;
			}
		}
		cout<<su%(998244353);
	}
	return 0;
}
