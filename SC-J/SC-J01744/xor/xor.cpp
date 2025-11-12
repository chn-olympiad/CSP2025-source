#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],s[N],x[N];
struct area
{
	int s,e;
};
vector<area> ar;
bool cmp(area p,area q)
{
	if(p.e==q.e) return p.s>q.s;
	return p.e<q.e;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]^s[i-1];
		x[i]=s[i]^k;
	}
	int ans=0;
	int siz=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(k==a[i])
				{
					area t;
					t.s=i;
					t.e=j;
					ar.push_back(t);
					siz++;
					//cout<<i<<' '<<j<<endl;
				}
			}
			else if(k==(s[j]^s[i-1]))
			{
				area t;
				t.s=i;
				t.e=j;
				ar.push_back(t);
				siz++;
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	sort(ar.begin(),ar.end(),cmp);
	int ed=0;
	for(int i=0;i<siz;i++)
	{
		if(ed<ar[i].s)
		{
			//cout<<ar[i].s<<' '<<ar[i].e<<endl;
			ans++;
			ed=ar[i].e;
		}
	}
	cout<<ans;
	return 0;	
} 