#include<bits/stdc++.h>
using namespace std;
inline int lowbit(int x)
{
	return x&-x;
}
vector<int> vec[500005];
int va[500005];
map<int,bool> vi;
bool vis[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>va[i];
		if(va[i]==k) vis[i]=1,ans++;
		vec[i].resize(20);
	}
	int cnt=0;
	for(int i=1,tmp;i<=n;i++)
	{
		tmp=va[i];
		cnt=1;
		while(tmp!=0)
		{
			vec[i][cnt]=lowbit(tmp);
			tmp-=lowbit(tmp);
			cnt++;
		}
	}
	int l=1,r=2;
	int sum1;
	for(;r<=n;r++)
	{
		if(vis[r])
		{
			l=r+1,r+=2;
			continue;
		}
		while(vis[l]) l++;
		for(int i=l;i<r;i++)
		{
			sum1=0;
			vi.clear();
			for(int p=i;p<=r;p++)
			{
				for(auto j:vec[p])
					vi[j]=1;
			}
			for(int p=i;p<=r;p++)
			{
				for(auto j:vec[p])
				{
					if(vi.find(j)==vi.end())
						sum1+=j;
				}
			}
			if(sum1==k)
			{
				for(int q=i;q<=r;q++)
					vis[q]=1,cout<<q;
				ans++;
			}
				
		}
	}
	cout<<ans+1;
}
