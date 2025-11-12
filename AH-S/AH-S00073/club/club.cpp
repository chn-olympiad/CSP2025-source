#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
	int num;
};
int t,n;
vector <node> a;
vector <node> s[5];
long long ans;
bool cmp(node a,node b)
{
	return a.num>b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--)
	{
		cin>>n;
		a.clear();
		int sum[5];
		sum[1]=sum[2]=sum[3]=0;
		for (int i=0;i<4;i++) s[i].clear();
		ans=0;
		for (int i=0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			node ss;
			ss.x=x,ss.y=y,ss.z=z;
			a.push_back(ss);
			if (a[i].x>=a[i].y && a[i].x>=a[i].z)
			{
				a[i].num=a[i].x-max(a[i].y,a[i].z);
				s[1].push_back(a[i]);
				ans+=a[i].x*1ll;
				sum[1]++;
			}
			else if (a[i].y>=a[i].x && a[i].y>=a[i].z)
			{
				a[i].num=a[i].y-max(a[i].x,a[i].z);
				s[2].push_back(a[i]);
				ans+=a[i].y*1ll;
				sum[2]++;
			}
			else
			{
				a[i].num=a[i].z-max(a[i].x,a[i].y);
				s[3].push_back(a[i]);
				ans+=a[i].z*1ll;
				sum[3]++;
			}
		}
		for (int i=1;i<=3;i++)
		{
			if (sum[i]<=n/2) continue;
			sort(s[i].begin(),s[i].end(),cmp);
			//cout<<'\n'<<i<<'\n';
			//for (int j=0;j<sum[i];j++)
			//{
				//cout<<s[i][j].num<<' ';
			//}cout<<'\n';
			for (int j=n/2;j<sum[i];j++)
			{
				ans-=s[i][j].num*1ll;
			}
			break;
		}
		cout<<ans<<'\n';
	}

	return 0;
}
