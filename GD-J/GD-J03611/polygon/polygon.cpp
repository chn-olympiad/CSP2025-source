#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxt=-100000000000000000,sum,maxx,k,kk,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxt=max(maxt,a[i]);
	if(maxt==1)
	{
		if(n<3)
			cout<<0;
		else
			cout<<((n-1)*(n-2)/2)%998244353;
		exit(0);
	}
	//sort(a+1,a+n+1);
	for(int i=1;i<=(1<<n)-1;i++)
	{
		sum=0,maxx=-100000000000000000,k=i,kk=1;
		while(1)
		{
			if(k%2==1)
				sum+=a[kk],maxx=max(maxx,a[kk]);
			k/=2,kk++;
			if(k==0)
				break;
		}
		if(sum>maxx*2)
			ans++,ans%=998244353;
	}
	cout<<ans;
	return 0;
}
