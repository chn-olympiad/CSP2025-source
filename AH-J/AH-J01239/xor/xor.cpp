#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
long long maxn,sum[500001],a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	//~ if(k<=1&&maxn<=1)
	//~ {
		int lst=0;
		for(int i=1;i<=n;i++)
		{
			if((sum[i]^sum[lst])==k)
			{
				//~ cerr<<sum[i]<<' ';
				ans++;
				lst=i;
			}
		}
		cout<<ans;
		//~ return 0;
	//~ }
	//~ int lst=0;
	//~ for(int i=1;i<=n;i++)
	//~ {
		//~ if((sum[i]^sum[lst])==k)
		//~ {
			//~ int l=lst+1,r=-1;
			//~ while(l<=i)
			//~ {
				//~ for(int j=i;j>l;j--)
				//~ {
					//~ if((sum[i]^sum[j-1])==(sum[l]^sum[lst]))
					//~ {
						//~ r=j;
						//~ break;
					//~ }
				//~ }
				//~ if(r!=-1)
					//~ break;
				//~ l++;
			//~ }
			//~ if(r
		//~ }
	//~ }
	//~ cout<<ans;
	return 0;
}
