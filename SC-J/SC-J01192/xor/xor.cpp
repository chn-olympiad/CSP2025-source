#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int N,K,A[500005];
int ans,vist[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
	}
	for(int i=1;i<=N;i++)
	{
		int L=1,R=L+i-1,sum=0,cnt=0;
		if(L==1)
		{
			sum=A[L];
			for(int j=L+1;j<=R;j++)
			{
				sum^=A[j];
			}
			if(sum==K)
			{
				for(int j=L;j<=R;j++)
				{
					if(vist[j])
					{
						break;
					}
					cnt++;
				}
				if(cnt==R-L+1)
				{
					for(int j=L;j<=R;j++)
					{
						vist[j]=1;
					}
					ans++;
				}
			}
			cnt=0;
			L++;
			R++;
		}
		while(R<=N)
		{
			sum^=A[L-1];
			sum^=A[R];
			if(sum==K)
			{
				for(int j=L;j<=R;j++)
				{
					if(vist[j])
					{
						break;
					}
					cnt++;
				}
				if(cnt==R-L+1)
				{
					for(int j=L;j<=R;j++)
					{
						vist[j]=1;
					}
					ans++;
				}
			}
			cnt=0;
			L++;
			R++;
		}
	}
	cout<<ans<<endl;
	return 0;
}