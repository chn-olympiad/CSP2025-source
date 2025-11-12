#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const LL N=5e5+9;
LL n,k,a[N],ans=-1;
bool A=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(LL i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) A=0;
	}
	if(A) cout<<n/2;
	else
	{
		for(LL i=0;i<(1<<n);i++)
		{
			LL s=0,cnt=0;
			bool f=0,flag=1;
			for(LL j=0;j<n;j++)
			{
				if((i>>j)&1&&!f)
				{
					s=a[j];
					cnt++;
					f=1;
				}
				else if((i>>j)&1&&f) s^=a[j];
				else if((!(i>>j)&1)&&f)
				{
					if(s!=k) flag=0;
					f=0;
				}
			}
			if(flag) ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}