#include <bits/stdc++.h>
using namespace std;
int t,n;
long long sum;
struct Node
{
	int v[5];
}a[100010];
struct stu
{
	int step;
	long long total;
	int b[5];
}q[53500010];
void bfs()
{
	int h=1,t=3;
	while(h<=t)
	{
		sum=max(sum,q[h].total);
		stu tmp=q[h];
		for(int i=1;i<=3;i++)
		{
			if(tmp.b[i]<n/2&&tmp.step<=n)
			{
				t++;
				q[t].total=tmp.total+a[tmp.step].v[i];
				for(int j=1;j<=3;j++)
					if(j==i) q[t].b[j]=tmp.b[j]+1;
					else q[t].b[j]=tmp.b[j];
				q[t].step=tmp.step+1;
			}
		}
		h++;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		sum=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[j].v[1],&a[j].v[2],&a[j].v[3]);
		}
		q[1].total=a[1].v[1];
		q[1].step=2;
		q[1].b[1]=1;
		bfs();
		q[1].total=a[1].v[2];
		q[1].step=2;
		q[1].b[2]=1;
		bfs();
		q[1].total=a[1].v[3];
		q[1].step=2;
		q[1].b[3]=1;
		bfs();
		cout<<sum<<endl;
	}
	return 0;
}
