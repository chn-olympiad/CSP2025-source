#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
ll n,k,a[N],ans=0,sum=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
 	cin >> n >> k;
 	for(int i=1;i<=n;i++)
 	{
 		cin >> a[i];
 		sum+=a[i];
	}
	if(k==0 && sum==n) // A
	{
		cout << n/2 << endl;
		return 0;
	}
	else if(k<=1 && sum<=n) // B
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 && a[i+1]==1){
					a[i+1]=2;
					ans++;
				}
				else if(a[i]==0) ans++;
			}
			cout << ans << endl;
		}
		else if(k==1)
		{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout << ans << endl;
		}
	}
	else if(k==0 && sum>n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1 && a[i+1]==1){
				a[i+1]=-1;
				ans++;
			}
			else if(a[i]==0) ans++;
		}
		cout << ans << endl;
	}
	else if(k>1 && sum<=n)
	{
		cout << 0 << endl;
	}
	return 0;
}
