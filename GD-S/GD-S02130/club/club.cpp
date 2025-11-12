#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct node
{
	int a,b,c,id;
};
vector<node>a(1);
priority_queue<int>q[3];
bool vis1[N],vis2[N],vis3[N];
bool cmp1(node a,node b)
{
	return a.a>b.a;
}
bool cmp2(node p,node q)
{
	return p.b>=q.b;
}
bool cmp3(node a,node b)
{
	return a.c>b.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int za,b,c;
			cin>>za>>b>>c;
			a.push_back({za,b,c,j});
		}
		int la=0,lb=0,lc=0,sum=0,k=n/2;
		auto ls1=a,ls2=a,ls3=a;
		sort(ls1.begin()+1,ls1.begin()+n,cmp1);
		for(int j=1;j<=n/2;j++)
		{
			la+=ls1[j].a;
			vis1[ls1[j].id]=true;
		}
		sort(ls2.begin()+1,ls2.end(),cmp2);
		for(int j=1;j<=n/2;j++)
		{
			lb+=ls2[j].b;
			vis2[ls2[j].id]=true;
		}
		sort(ls3.begin()+1,ls3.begin()+n,cmp3);
		for(int j=1;j<=n/2;j++)
		{
			lc+=ls3[j].c;
			vis3[ls3[j].id]=true;
		}
		if(la>=lb&&la>=lc)
		{
			memset(vis2,0,sizeof vis2);
			memset(vis3,0,sizeof vis3);
			sum+=la;
			int p=1,q=1;
			while(k<=n)
			{
				if(ls2[p].b>=ls3[q].c&&!vis1[p]&&!vis2[p]&&!vis3[p])
				{
					sum+=ls2[p].b;
					vis2[ls2[p].id]=true;
					p++;
					k++;
				}
				else if(ls2[p].b<ls3[q].c&&!vis1[q]&&!vis2[q]&&!vis3[q])
				{
					sum+=ls3[q].c;
					vis3[ls3[q].id]=true;
					q++;
					k++;
				}
				else
				{
					if(ls2[p+1].b>ls3[q+1].c)
					{
						p++;
					}
					else
					{
						q++;
					}
				}
			}
		}
		else if(lb>=la&&lb>=lc)
		{
			memset(vis1,0,sizeof vis1);
			memset(vis3,0,sizeof vis3);
			sum+=lb;
			int p=1,q=1;
			while(k<=n)
			{
				if(ls1[p].a>=ls3[q].c&&!vis1[p]&&!vis2[p]&&!vis3[p])
				{
					sum+=ls1[p].a;
					vis1[ls1[p].id]=true;
					p++;
					k++;
				}
				else if(ls1[p].a<ls3[q].c&&!vis1[q]&&!vis2[q]&&!vis3[q])
				{
					sum+=ls3[q].c;
					vis3[ls3[q].id]=true;
					q++;
					k++;
				}
				else
				{
					if(ls1[p+1].a>ls3[q+1].c)
					{
						p++;
					}
					else
					{
						q++;
					}
					k++;
				}
			}
		}
		else if(lc>=la&&lc>=lb)
		{
			memset(vis2,0,sizeof vis2);
			memset(vis1,0,sizeof vis1);
			sum+=lc;
			int p=1,q=1;
			while(k<=n)
			{
				if(ls1[p].a>=ls2[q].b&&!vis1[p]&&!vis2[p]&&!vis3[p])
				{
					sum+=ls1[p].a;
					vis1[ls1[p].id]=true;
					p++;
					k++;
				}
				else if(ls1[p].a<ls2[q].b&&!vis1[q]&&!vis2[q]&&!vis3[q])
				{
					sum+=ls2[q].b;
					vis2[ls2[q].id]=true;
					q++;
					k++;
				}
				else
				{
					if(ls1[p+1].a>ls2[q+1].b)
					{
						p++;
					}
					else
					{
						q++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
1
4
0 1 0
0 1 0
0 2 0
0 2 0
1
2
10 9 8
4 0 0f
*/
