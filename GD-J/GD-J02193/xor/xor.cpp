#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],id,i,j,s,ans;
bool ok[(1<<20)+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	j=1;
	ok[0]=true;
	for(i=1;i<=n;i++)
	{
		s^=a[i];
		if(ok[s^k])
		{
			ans++;
			s=0;
			for(;j<=i;j++)
			{
				s^=a[j];
				ok[s]=false;
			}
			ok[0]=true;
			s=0;
		}
		ok[s]=true;
	}
	cout<<ans;
	return 0;
}
