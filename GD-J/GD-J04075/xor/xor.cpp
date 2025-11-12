#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	int num,lim=1,ans=0;
	vector<int> pre(n+1);
	for(int j=1;j<=n;j++)
	{
		cin>>num;
		pre[j]=pre[j-1]^num;
		//cout<<pre[j]<<" ";
		for(int i=lim;i<=j;i++)
		{
			if((pre[j]^pre[i-1])==k)
			{
				ans++,lim=j+1;
				//cout<<pre[i-1]<<" "<<pre[j]<<"\n";
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
