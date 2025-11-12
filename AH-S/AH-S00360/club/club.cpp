#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N=1e5+1;
int n;
struct node{
	int a,b,c;
	int sum;
	int m;
	int w;
}a[N];
bool cmp(node a,node b)
{
	if(a.sum!=b.sum) return a.sum>b.sum;
	return a.m>b.m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].sum=a[i].a+a[i].b+a[i].c;
			a[i].m=max(a[i].a,max(a[i].b,a[i].c));
		}
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].m;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
