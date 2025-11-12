#include <bits/stdc++.h>
using namespace std;
const int kmaxn=1.05e6+1;	// 2^20 = 1048576 < 1.05*(10^6)
const int nmaxn=5e5+1;
const int gapmaxn=268183440;
// yi huo fu hao: '^'
int n;
int k;
int ans=0;
int a[nmaxn];
struct Node
{
	int l;
	int r;
} gap[gapmaxn];
int gapnum=0;
bool cmp(Node a,Node b)
{
	return a.r<=b.r;
}
int cal(int l,int r)
{
	int res=0;
	for(int i=l;i<=r;i++)
	{
		res=res^(a[i]);
	}
	return res;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(a,0,sizeof(a));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int tail=0;
	for(int j=1;j<=n;j++)
	{
		for (int i=1;i<=j;i++)
		{
			if(i<=tail)
			{
				continue;
			}
			int curr=cal(i,j);
			if(curr==k)	// a good answer, we can record it
			{
				gapnum++;
				gap[gapnum].l=i;
				gap[gapnum].r=j;
				tail=j;
				ans++;
			}
			/*
			cout<<"i: "<<i<<endl;
			cout<<"j: "<<j<<endl;
			cout<<"curr: "<<curr<<endl;
			cout<<"gapnum: "<<gapnum<<endl;
			cin.get();
			*/
		}
	}
	/*
	for(int i=1;i<=gapnum;i++)
	{
		cout<<"i: "<<i;
		cout<<gap[gapnum]<<endl;
	}
	cin.get();
	*/
	cout<<ans<<endl;
	return 0;
}
