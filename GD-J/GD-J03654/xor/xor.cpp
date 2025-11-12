#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5*1e5+5;
ll n,k,a[N],ch[N];

bool check(ll ans)
{
	ll sum0=-1,head=0,tail=0,he=0;
	for(ll i=1;i<=n;i++)
	{
		ll sum=0;
		for(head=i,tail=i;tail<=n&&head<=n;)
		{
			he=(he ^ a[tail]);
			if(he==k) 
			{
				sum++;
				head=tail+1,tail++;
				he=0;
			}
			else tail++;
		}
		sum0=max(sum0,sum);
	}
	
	return sum0>=ans;
}
//调试 
void check1(ll ans)
{
	ll sum0=-1,head=0,tail=0,he=0;
	for(ll i=1;i<=n;i++)
	{
		ll sum=0;
		for(head=i,tail=i;tail<=n&&head<=n;)
		{
			he=(he ^ a[tail]);
			if(he==k) 
			{
				sum++;
				cout<<head<<' '<<tail<<endl;
				head=tail+1,tail++;
				he=0;
			}
			else tail++;
		}
		sum0=max(sum0,sum);
	}
	
}
 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	//预处理前或和
//	ch[0]=0;
//	ch[1]=a[1];
//	for(ll i=2;i<=n;i++) ch[i]=ch[i-1] ^ a[i];
	
	//枚举ans
	ll l=0,r=N,ans=0;
	//调试
//	for(ll i=N;i>=1;i--) 
//	{
//		if(check(i)) 
//		{
//			cout<<i;
//			return 0;
//		}
//	}
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;

//	for(ll i=1;i<=n;i++) cout<<ch[i]<<' ';
//	check1(69);
	return 0;
}
