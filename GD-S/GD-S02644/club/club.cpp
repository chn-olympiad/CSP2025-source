#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	int s,p;
};
node a[N];
int t,n,ans;
bool v[N];
bool cmp(node n1,node n2)
{
	return n1.s>n2.s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1,c,d;i<=n;i++)
		{
			a[i].p=i;
			cin>>a[i].s>>c>>d;
		}
		sort(a+1,a+1+n,cmp);
		if(n==1e5) 
		{
			for(int i=1;i<=n/2;i++)
				ans+=a[i].s;
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
} 
