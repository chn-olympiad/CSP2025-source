#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define il inline
using namespace std;

const int MAXN=1e5+7;
const int MAXM=1e2+7;

int n,ans,a[MAXN][3],b[MAXN],w[3],da[MAXN],db[MAXN],dc[MAXN];
int ia[MAXN],ib[MAXN],ic[MAXN],bz[MAXN],f[MAXM][MAXM/2][MAXM/2][MAXM/2];

struct node {
	int a,b,c,maxx;
} d[MAXN];

struct Node {
	int id,val;
	bool operator < (const Node& x) const {
		return val<x.val;
	}
};

priority_queue<Node> q[3];

bool cmp(int x,int y) {return x>y;}

bool cmpa(int x,int y) {return da[x]>da[y];}
bool cmpb(int x,int y) {return db[x]>db[y];}
bool cmpc(int x,int y) {return dc[x]>dc[y];}

bool cmmp(node x,node y) {return x.maxx>y.maxx;}

void dfs(int t,int s1,int s2,int s3,int sum)
{
//	if(sum<=f[t][s1][s2][s3])
//		return ;
	f[t][s1][s2][s3]=sum;
	ans=max(ans,sum);
	if(t>n)
		return ;
	if(s1<n/2)dfs(t+1,s1+1,s2,s3,sum+a[t][0]);
	if(s2<n/2)dfs(t+1,s1,s2+1,s3,sum+a[t][1]);
	if(s3<n/2)dfs(t+1,s1,s2,s3+1,sum+a[t][2]);
}

int main()
{
//	fre("club5");
	fre("club");
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		int t2,t3;
		t2=t3=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
//				cout<<j<<endl;
				int in;
				scanf("%d",&in);
				a[i][j-1]=in;
				if(j==2)
					t2+=in;
				if(j==3)
					t3+=in;
			}
			b[i]=a[i][0];
			d[i]={a[i][0],a[i][1],a[i][2],max(max(a[i][0],a[i][1]),a[i][2])};
			da[i]=d[i].a,db[i]=d[i].b,dc[i]=d[i].c;
			ia[i]=ib[i]=ic[i]=i;
		}
		if(!t2 and !t3)
		{
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=b[i];
			}
			printf("%d\n",ans);
		}
		dfs(1,0,0,0,0);
//		int sum=0;
//		sort(d+1,d+n+1,cmmp);
//		for(int i=1;i<=n;i++)
//		{
//			int maxt=0;
//			for(int j=0;j<3;j++)
//			{
//				if(a[i][j]>a[i][maxt])
//					maxt=i;
//			}
//			Node g=q[maxt];
//			int ot=0;
//			for(int j=0;j<3;j++)
//			{
//				if(j==maxt)
//					continue ;
//				ot=max(ot,a[g.val][j]);
//			}
//			if(q[maxt].size()==n/2 and sum-g.val+ot+a[i][maxt]>sum)
//			{
//				sum=sum-g.val+ot+a[i][maxt];
//				q[maxt].pop(),q[maxt].push({i,a[i][maxt]});
//			}
//			else
//			{
//				ot=0;
//				for(int j=0;j<3;j++)
//				{
//					if(j==maxt)
//						continue ;
//					ot=max(ot,a[i][j]);
//				}
//				sum+=ot;
//			}
//		}
//		sort(ia+1,ia+n+1,cmpa);
//		sort(ib+1,ib+n+1,cmpb);
//		sort(ic+1,ic+n+1,cmpc);
//		for(int i=1;i<=n;i++)
//		{
//			if(bz[ia[i]])
//				continue ;
//			if(da[ia[i]]>db[ib[i]] and da[ia[i]]>dc[ic[i]])
//			{
//				bz[ia[i]]=1;
//				if(q[0].size()==n/2)
//				{
//					Node get=q[0].top();
//					if(sum<sum-get.val+max(db[get.id],dc[get.id])+da[ia[i]])
//					{
//						sum=sum-get.val+max(db[get.id],dc[get.id])+da[ia[i]];
//						q[0].pop(),q[0].push({ia[i],da[ia[i]]});
//					}
//				}
//				else
//				{
//					bz[ia[i]]=1;
//					q[0].push({ia[i],da[ia[i]]});
//					sum+=da[ia[i]];
//				}
//			}
//			if(db[ib[i]]>da[ia[i]] and db[ib[i]]>dc[ic[i]])
//			{
//				bz[ib[i]]=1;
//				if(q[1].size()==n/2)
//				{
//					Node get=q[1].top();
//					if(sum<sum-get.val+max(da[get.id],dc[get.id])+db[ib[i]])
//					{
//						sum=sum-get.val+max(da[get.id],dc[get.id])+db[ib[i]];
//						q[1].pop(),q[1].push({ib[i],db[ib[i]]});
//					}
//				}
//				else
//				{
//					bz[ib[i]]=1;
//					q[1].push({ib[i],db[ib[i]]});
//					sum+=db[ib[i]];
//				}
//			}
//			if(dc[ic[i]]>da[ia[i]] and dc[ic[i]]>db[ib[i]])
//			{
//				bz[ic[i]]=1;
//				if(q[2].size()==n/2)
//				{
//					Node get=q[2].top();
//					if(sum<sum-get.val+max(da[get.id],db[get.id])+dc[ic[i]])
//					{
//						sum=sum-get.val+max(da[get.id],db[get.id])+dc[ic[i]];
//						q[2].pop(),q[2].push({ic[i],dc[ic[i]]});
//					}
//					else
//					{
//						
//					}
//				}
//				else
//				{
//					q[2].push({ic[i],dc[ic[i]]});
//					sum+=dc[ic[i]];
//				}
//			}
//		}
		printf("%d\n",ans);
	}
	return 0;
}
