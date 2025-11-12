#include<iostream>
using namespace std;
typedef long long ll;
const ll N=1e5*5+10;
ll n,k,ans1=0,ans2=0;
ll a[N];
bool flag_yi=1,flag_ling=1;
void dfs(ll s,ll p,ll sum)
{
	if(p>n)
		return;
	if(s==k)
	{
		dfs(a[p+1],p+1,sum+1);
		dfs((s^a[p]),p+1,sum);
	}
	dfs(s,p+1,sum+1);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			flag_yi=0;
		if(a[i]!=0)
			flag_ling=0;
		if(a[i]==k)
			ans1++;
	}
	if((flag_yi==1&&k==0)||(flag_ling==1&&k==1))
	{
		cout<<n/2;
		return 0;
	}
	if(n<=10)
		dfs(-1,1,0);
	cout<<max(ans1,ans2);
	return 0;
}
