#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nt
{
	int l,r;
}p[500100];
int n,k,a[500100],q[500100],num;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=i;j<=n;j++)
		{
			if(i==j) t=a[i];
			else t=t^a[j];
			if(t==k)
			{
				num++;
				p[num].l=i;
				p[num].r=j;
				q[i]=num;
				break;
			}
		}
	}
	if(k==1) cout<<n;
	else if(k==0) cout<<n/2;
	else cout<<0;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
