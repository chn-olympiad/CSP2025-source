#include<bits/stdc++.h>
using namespace std;
const int N=5e5+520;
const int T=1e3+10;
int n,k;
int a[N];
int sxor[N];
int ans=0;
struct node{
	int l,r;
};
bool cmp(node p,node q)
{
	return p.r<q.r;
}
int now=0;
vector<node> b;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sxor[i]=sxor[i-1]^a[i];
	}
	if(n<=T)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int sx=sxor[j]^sxor[i-1];
				if(sx==k)
				{
					b.push_back({i,j});
					break;
				}
			}
		}
		sort(b.begin(),b.end(),cmp);
		int len=b.size();
		for(int i=0;i<len;i++)
		{
			if(b[i].l>now) 
			{
				ans++;
				now=b[i].r;
			}
		}
		cout<<ans<<endl;	
	}
	else{
		int last=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j>=last;j--)
			{
				int sx=sxor[i]^sxor[j-1];
				if(sx==k)
				{
					last=i+1;
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 