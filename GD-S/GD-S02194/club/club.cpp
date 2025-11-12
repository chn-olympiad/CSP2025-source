#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{int b[4];}aa[N];int sum[4],c[4],ans[N],v[4];int n;
deque<int>G[4];int id;
bool cmp1(node n1,node n2){return n1.b[1]+n1.b[2]+n1.b[3]>n2.b[1]+n2.b[2]+n1.b[3];}

void clearr()
{
	G[1].clear();
	G[2].clear();
	G[3].clear();
	memset(sum,0,sizeof(sum));
	memset(aa,0,sizeof(aa));
	memset(v,0,sizeof(v));
}
int find(int x)
{
	int mx=0x3f3f3f3f,iid;
	for(int i=1;i<=3;i++)
	{
		if(v[i])continue;
		int ssum=aa[x].b[c[id]]-aa[x].b[i];
		if(ssum<mx)mx=ssum,iid=i;
	}
	return iid;
}
bool cmp(int a,int b)
{
	int fd1=find(a),fd2=find(b);
	return (aa[a].b[c[id]]-aa[a].b[fd1])<(aa[b].b[c[id]]-aa[b].b[fd2]);
}
void work(int x,int iid)
{
	id=iid;
	if(sum[x]<=n/2)return;
	v[x]=1;
	int l=sum[x]-n/2;
	sort(G[x].begin(),G[x].end(),cmp);
	for(int i=0;i<l;i++)
	{
//		printf("%d\n",G[x].front());
		int nxt=find(G[x].front());
		ans[G[x].front()]=nxt;G[nxt].push_back(G[x].front());
		sum[nxt]++,sum[c[iid]]--;
		G[x].pop_front();
	}
}
void solve()
{
	cin>>n;clearr();
	for(int i=1;i<=n;i++)cin>>aa[i].b[1]>>aa[i].b[2]>>aa[i].b[3];
//	sort(aa+1,aa+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(aa[i].b[1]>=aa[i].b[2]&&aa[i].b[1]>=aa[i].b[3])sum[1]++,ans[i]=1,G[1].push_back(i);
		else if(aa[i].b[2]>=aa[i].b[1]&&aa[i].b[2]>=aa[i].b[3])sum[2]++,ans[i]=2,G[2].push_back(i);
		else if(aa[i].b[3]>=aa[i].b[1]&&aa[i].b[3]>=aa[i].b[2])sum[3]++,ans[i]=3,G[3].push_back(i);
	}
//	id=1;v[1]=1;cout<<find(2)<<endl;return ;
//	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	c[1]=1,c[2]=2,c[3]=3;
	sort(c+1,c+4,[](int x,int y){return sum[x]>sum[y];});
	for(int i=1;i<=3;i++)work(c[i],i);
//	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	int num=0;
	for(int i=1;i<=n;i++)num+=aa[i].b[ans[i]];
	cout<<num<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
