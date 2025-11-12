#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+5;
struct Node
{
	int l,r;
	Node(int _l=0,int _r=0):l(_l),r(_r){}
	bool operator<(const Node &tmp)const
	{
		return r<tmp.r;
	}
};
int n,k,a[N],pre[N];
long long ans=0;
vector<Node>Line;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((pre[i-1]^pre[j])==k)
				Line.push_back({i,j});
	sort(Line.begin(),Line.end());
	int r_end=-1;
	for(auto v:Line)
	{
		if(v.l>r_end)
			ans++,r_end=v.r;
	}
	cout<<ans<<'\n';
	return 0;
}