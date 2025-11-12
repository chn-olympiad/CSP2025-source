#include<bits/stdc++.h>
using namespace std;
int permutation[606],kk[606];
long long n,m,a[606],ans;
string s;
bool check()
{
	int supper=0,ll=0;
	for(int i=0;i<n;++i)
	{
		kk[i]=a[permutation[i]];
	}
	
	for(int i=0;i<n;++i)
	{
		if(s[i]!='1')
		{
			ll++;
			continue;
		}
		if(ll>=kk[i])
		{
			ll++;
		}
		else
		{
			supper++;
		}
	}
	return supper>=m;
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		permutation[i]=i;
	}
	do
	{
		ans+=check();
		
	}while(next_permutation(permutation,permutation+n));
	cout<<ans%998244353;
	return 0;
}
