#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5000005];
ll fp(ll a,ll b)
{
	ll ans=1;
	for(int i=1;i<=b;i++)
		ans*=a;
	return ans;
}
ll nxor(ll a,ll b)
{
	ll ans=0,t,n=1,cnt=0;
	if(a>b)
		t=a;
	else
		t=b;
	while(1)
	{
		//cout<<cnt<<endl;
		if(t/n==0)
		{
			cnt--;
			break;
		}
		n*=2;
		cnt++;
	}
	//cout<<"		cnt:"<<cnt<<endl;
	while(1)
	{
		if(a==0&&b==0)
			break;
		ll fc=fp(2,cnt);
		//cout<<"		fc:"<<fc<<endl;
		ans*=2;
		ans+=!(a/fc&b/fc);
		a%=fc,b%=fc;
		cnt--;
		//cout<<"		a/b:"<<a<<" "<<b<<endl;
		//cout<<"		ans:"<<ans<<endl;
		//system("pause");
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,cnt=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	//cout<<(n&k)<<" "<<!(n&k);
	//cout<<nxor(n,k);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			int asn=-1;
			//cout<<"i/j"<<i<<" "<<j<<endl;
			for(int w=i;w<=j;w++)
			{
				if(asn==-1)
				{
					asn=a[w];
					//cout<<"	continue,asn="<<asn<<endl;
					continue;
				}
				//cout<<"	asn/a[w]:"<<asn<<" "<<a[w]<<endl;
				asn=nxor(asn,a[w]);
				//cout<<"	asn"<<asn<<endl;
			}
			if(asn==k)
			{
				cnt++;
				//cout<<"			find:"<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<cnt;
	return 0;
}
