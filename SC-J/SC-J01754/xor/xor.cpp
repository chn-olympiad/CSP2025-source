#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int s[500005];
bool p[1048580];

int cnt;

int c[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int ans=0;
	cnt=1;
	p[0]=1;
	c[1]=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<"!"<<i<<" "<<p[1]<<" "<<p[0]<<"!\n";
//		if(a[i]==k)
//		{
//			ans++;
////			cout<<i<<" ";
//			for(int j=1;j<=cnt;j++)
//			{
//				p[c[j]]=0;
//			}
//			cnt=0;
////			cout<<"?"<<i<<" "<<p[1]<<" "<<p[0]<<"?\n";
//			continue;
//		}
		int x=s[i]^k;
		if(p[x]==1)
		{
			ans++;
//			cout<<i<<" ";
			for(int j=1;j<=cnt;j++)
			{
				p[c[j]]=0;
			}
			cnt=0;
//			cout<<"?"<<i<<" "<<p[1]<<" "<<p[0]<<"?\n";
		}
		p[s[i]]=1;
		c[++cnt]=s[i];
	}
	cout<<ans;
	return 0;
}