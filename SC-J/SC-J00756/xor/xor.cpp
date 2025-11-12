#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans,cnt[500005],flag,vis[500005],m=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j<=i;j++)
		{
//			if(cnt[j]<0||a[i]<0)
//			continue;
//			if(vis[j]==1||vis[i]==1)
//			{
//				cnt[j]=-1;
//				continue;
//			}
			cnt[j]=cnt[j] xor a[i];
			if(cnt[j]==k)
			{
				for(int q=j;q<=i;q++)
				{
					if(vis[q]==1)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					ans++;
					for(int q=j;q<=i;q++)
					{
						vis[q]=1;
						a[q]=-1;
					}
					m=i;
//					cout<<j<<" "<<i<<",";
				}
				cnt[j]=-1;
				flag=0;
			}
		}
	}
	cout<<ans;
	return 0;
}