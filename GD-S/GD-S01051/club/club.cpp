#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
struct Node
{
	int x, y, z;
}v[N];
int a[N][4], a1[N], a2[N], a3[N];
bool cmp(Node x, Node y)
{
	return (x.x<y.x&&x.y<y.y)?1:((x.x>y.x&&x.y>y.y)?0:(x.x>y.x)?x.x-y.x>y.y-x.y:y.x-x.x>x.y-y.y);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n, ans=0, n1=0, n2=0, n3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxn=max(max(a[i][1], a[i][2]), a[i][3]);
			if(a[i][1]==maxn)
				a1[++n1]=i;
			else if(a[i][2]==maxn)
				a2[++n2]=i;
			else
				a3[++n3]=i;
		}
		int maxn=max(n1, max(n2, n3));
		for(int i=1;i<=maxn;i++)
		{
			if(i<=n1)
				ans+=a[a1[i]][1];
			if(i<=n2)
				ans+=a[a2[i]][2];
			if(i<=n3)
				ans+=a[a3[i]][3];
		}
		if(n1>n/2)
		{
			int tot=0;
			for(int i=1;i<=n1;i++)
				v[++tot]=(Node){a[a1[i]][1]-a[a1[i]][2], a[a1[i]][1]-a[a1[i]][3], i};
			sort(v+1, v+tot+1, cmp);
//			for(int i=1;i<=tot;i++)
//				cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
//			cout<<endl<<endl;
			for(int i=n1;i>n/2;i--)
			{
				Node t=v[n1-i+1];
//				a1[t.z]=0;
//				if(t.x>t.y)
//					a2[++n2]=t.z;
//				else
//					a3[++n3]=t.z;
				ans-=(t.x<t.y)?t.x:t.y;
			}
		}
		else if(n2>n/2)
		{
			int tot=0;
			for(int i=1;i<=n2;i++)
				v[++tot]=(Node){a[a2[i]][2]-a[a2[i]][1], a[a2[i]][2]-a[a2[i]][3], i};
			sort(v+1, v+tot+1, cmp);
//			for(int i=1;i<=tot;i++)
//				cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
//			cout<<endl<<endl;
			for(int i=n2;i>n/2;i--)
			{
				Node t=v[n2-i+1];
//				a2[t.z]=0;
//				if(t.x>t.y)
//					a1[++n1]=t.z;
//				else
//					a3[++n3]=t.z;
				ans-=(t.x<t.y)?t.x:t.y;
			}
		}
		else if(n3>n/2)
		{
			int tot=0;
			for(int i=1;i<=n3;i++)
				v[++tot]=(Node){a[a3[i]][3]-a[a3[i]][1], a[a3[i]][3]-a[a3[i]][2], i};
			sort(v+1, v+tot+1, cmp);
//			for(int i=1;i<=tot;i++)
//				cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
//			cout<<endl<<endl;
			for(int i=n3;i>n/2;i--)
			{
				Node t=v[n3-i+1];
//				a3[t.z]=0;
//				if(t.x>t.y)
//					a1[++n1]=t.z;
//				else
//					a2[++n2]=t.z;
				ans-=(t.x<t.y)?t.x:t.y;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
