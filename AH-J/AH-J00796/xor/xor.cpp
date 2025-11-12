#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],s[500005],ans=0;
//~ void sovlve1()
//~ {
	
	
//~ }
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	//~ bool sAB=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		//~ cout<<s[i]<<" ";
	}
	//~ cout<<"\n";
	int lst=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=lst;j<=i;j++)
		{
			if((s[i]^s[j-1])==k)
			{
				//~ cout<<i<<" "<<j<<"\n";
				ans++;
				lst=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*

4 3
2 1 0 3

 * */
