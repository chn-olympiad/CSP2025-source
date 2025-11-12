#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>
#include<utility>
#include<vector>
using namespace std;
#define pr pair<int,int>
struct node
{
	int a[4],rnk[4];
	int nwn;
}tr[100100];
struct srt
{
	int lr,id;
}r[4];
int cmp(srt lx,srt ly)
{
	if(lx.lr!=ly.lr)return lx.lr>ly.lr;
	else return lx.id<ly.id;
}
int v[4];
priority_queue<pr,vector<pr>,greater<pr> >q[4];
int n;
void init()
{
	for(int i=1;i<=3;i++)
	{
		while(!q[i].empty())
		{
			q[i].pop();
		}
	}
	for(int i=1;i<=3;i++)
	v[i]=0;
	memset(tr,0,sizeof(tr));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		init();
		for(i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>r[j].lr;
				tr[i].a[j]=r[j].lr;
				r[j].id=j;
			}
			sort(r+1,r+3+1,cmp);
			for(int j=1;j<=3;j++)
			{
				//cout<<r[j].lr<<endl;
				tr[i].rnk[j]=r[j].id;
			//	cout<<tr[i].rnk[j]<<" ";
			}
		//	cout<<endl<<"/";
			//cin>>tr[i].a[1]>>tr[i].a[2]>>tr[i].a[3];
		//	q.push(make_pair(max(tr[i].a[1],tr[i].a[2],tr[i].a[3]),i));
		}
		int sum=0;
		for(i=1;i<=n;i++)
		{
			int nw=tr[i].rnk[1];
			int llnw=tr[i].rnk[2];
		//	cout<<nw<<" /";
		//	cout<<v[nw]<<endl;
			if(v[nw]==n/2)
			{
				int lq1=q[nw].top().first;
			//	cout<<lq1<<"///"<<endl;
				int lq2=q[nw].top().second;
			//	int lqn=tr[lq2].rnk[tr[lq2].nwn+1];
			//	cout<<lqn<<endl;
				if(lq1<tr[i].a[nw]-tr[i].a[llnw])
				{
				//	cout<<-lq1+tr[lq2].a[lqn]+tr[i].a[nw]<<endl;
					sum+=-lq1+tr[i].a[nw];
					q[nw].pop();
					tr[i].nwn=1;
					q[nw].push(make_pair(tr[i].a[nw]-tr[i].a[llnw],i));
					
					tr[lq2].nwn++;
					int nxt=tr[lq2].rnk[tr[lq2].nwn];
					int lnxt=tr[lq2].rnk[tr[lq2].nwn+1];
				//	cout<<lq2<<" "<<nxt<<"/"; 
					v[nxt]++; 
					q[nxt].push(make_pair(tr[lq2].a[nxt]-tr[lq2].a[lnxt],lq2));
				}
				else
				{
					nw=tr[i].rnk[2];
					v[nw]++;
					int lnn=tr[i].rnk[3];
					q[nw].push(make_pair(tr[i].a[nw]-tr[i].a[lnn],i));
					tr[i].nwn=2;
					sum+=tr[i].a[nw];
				}
			}
			else
			{
				int lnn=tr[i].rnk[2];
				q[nw].push(make_pair(tr[i].a[nw]-tr[i].a[lnn],i));
				sum+=tr[i].a[nw];
				v[nw]++; 
				tr[i].nwn=1;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

