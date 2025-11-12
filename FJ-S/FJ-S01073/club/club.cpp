#include<bits/stdc++.h>
#define N 100010
#define pri priority_queue
using namespace std;
int T;
int n,ans;
int a[N][4];
struct node1
{
	int id;
	int dat;
	bool operator<(const node1 &z)const
	{
		return a[id][1]-max(a[id][2],a[id][3])>a[z.id][1]-max(a[z.id][2],a[z.id][3]);
	}
}aa;
struct node2
{
	int id;
	int dat;
	bool operator<(const node2 &z)const
	{
		return a[id][2]-max(a[id][1],a[id][3])>a[z.id][2]-max(a[z.id][1],a[z.id][3]);
	}
}bb;
struct node3
{
	int id;
	int dat;
	bool operator<(const node3 &z)const
	{
		return a[id][3]-max(a[id][1],a[id][2])>a[z.id][3]-max(a[z.id][1],a[z.id][2]);
	}
}cc;
pri<node1>pa;
pri<node2>pb;
pri<node3>pc;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		int ff=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0)
			{
				ff=0;
			}
		}
		if(ff)
		{
			int cnt=0,tot=0;
			int s[N];
			for(int i=1;i<=n;i++)
			{
				s[++cnt]=a[i][1];
			}
			sort(s+1,s+cnt+1);
			for(int i=cnt;i>=1;i--)
			{
				tot++;
				ans+=s[i];
				if(tot==(n>>1))
				{
					cout<<ans;
					break;
				}
			}
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				aa.id=i;
				aa.dat=a[i][1];
				if(pa.size()<(n>>1))
				{
					pa.push(aa);
				}
				else
				{
					node1 q=pa.top();
					if(q.dat<max(a[q.id][2],a[q.id][3])+aa.dat)
					{
						pa.pop();
						pa.push(aa);
						if(a[q.id][2]>=a[q.id][3])
						{
							bb.id=q.id;
							bb.dat=a[q.id][2];
							pb.push(bb);
						}
						else
						{
							cc.id=q.id;
							cc.dat=a[q.id][3];
							pc.push(cc);
						}
					}
					else
					{
						if(a[i][2]>=a[i][3])
						{
							bb.id=i;
							bb.dat=a[i][2];
							pb.push(bb);
						}
						else
						{
							cc.id=i;
							cc.dat=a[i][3];
							pc.push(cc);
						}
					}
				}
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])
			{
				bb.id=i;
				bb.dat=a[i][2];
				if(pb.size()<(n>>1))
				{
					pb.push(bb);
				}
				else
				{
					node2 q=pb.top();
					if(q.dat<max(a[q.id][1],a[q.id][3])+bb.dat)
					{
						pb.pop();
						pb.push(bb);
						if(a[q.id][1]>=a[q.id][3])
						{
							aa.id=q.id;
							aa.dat=a[q.id][1];
							pa.push(aa);
						}
						else
						{
							cc.id=q.id;
							cc.dat=a[q.id][3];
							pc.push(cc);
						}
					}
					else
					{
						if(a[i][1]>=a[i][3])
						{
							aa.id=i;
							aa.dat=a[i][1];
							pa.push(aa);
						}
						else
						{
							cc.id=i;
							cc.dat=a[i][3];
							pc.push(cc);
						}
					}
				}
			}
			else
			{
				cc.id=i;
				cc.dat=a[i][3];
				if(pc.size()<(n>>1))
				{
					pc.push(cc);
				}
				else
				{
					node3 q=pc.top();
					if(q.dat<max(a[q.id][1],a[q.id][2])+cc.dat)
					{
						pc.pop();
						pc.push(cc);
						if(a[q.id][1]>=a[q.id][2])
						{
							aa.id=q.id;
							aa.dat=a[q.id][1];
							pa.push(aa);
						}
						else
						{
							bb.id=q.id;
							bb.dat=a[q.id][2];
							pb.push(bb);
						}
					}
					else
					{
						if(a[i][1]>=a[i][2])
						{
							aa.id=i;
							aa.dat=a[i][1];
							pa.push(aa);
						}
						else
						{
							bb.id=i;
							bb.dat=a[i][2];
							pb.push(bb);
						}
					}
				}
			}
		}
		while(!pa.empty())
		{
			aa=pa.top();
			pa.pop();
			ans+=aa.dat;
//			cout<<"aa "<<aa.id<<" "<<aa.dat<<"\n";
		}
		while(!pb.empty())
		{
			bb=pb.top();
			pb.pop();
			ans+=bb.dat;
//			cout<<"bb "<<bb.id<<" "<<bb.dat<<"\n";
		}
		while(!pc.empty())
		{
			cc=pc.top();
			pc.pop();
			ans+=cc.dat;
//			cout<<"cc "<<cc.id<<" "<<cc.dat<<"\n";
		}
		cout<<ans<<"\n";
	}
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
