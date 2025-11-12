#include<bits/stdc++.h>
using namespace std;
long long vis[110],c[110];
struct node
{
	long long u,v,w;
}tp[100010];
long long fa[4000100];
long long ctn,cnt; 
long long n,m,k;
bool operator <(node xx,node yy){
	return xx.w>yy.w;
}
priority_queue<node>q1,q2; 
long long find(long long x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
long long kr()
{
	long long sum=0,ans=0;
	for(long long i=1;i<=(n+k);i++){
		fa[i]=i;
	}
	//cout<<q2.size()<<"@@"<<endl;
	for(long long i=1;i<=cnt;i++)
	{
		long long uu=q2.top().u,vv=q2.top().v;
		long long xx=find(uu),yy=find(vv);
		//cout<<uu<<" "<<vv<<endl;
		if(xx!=yy){
			fa[xx]=yy;sum++;
			ans+=q2.top().w;
			if(sum==(ctn-1)){
//				cout<<ans<<"##"<<endl;
				return ans;
			}
		}
		q2.pop();
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cnt++;
		long long x,y,z;
		cin>>x>>y>>z;
		q1.push((node){x,y,z});
	}
	q2=q1;ctn=n;
	long long lst=kr();
	long long ss=0;
	for(long long i=1;i<=k;i++)
	{
		q2=q1;long long cst;
		cin>>cst;
		for(long long j=1;j<=n;j++)
		{
			long long zz;
			cin>>zz;
			tp[j].u=n+i;tp[j].v=j;tp[j].w=zz;
			q2.push((node){n+i,j,zz});
		}
		long long tmp1=lst;
		ctn++;cnt+=n;
		long long tmp2=kr()+cst;
		if(tmp2>tmp1){
			ctn--;cnt-=n;
		}
		else{
			for(long long j=1;j<=n;j++){
				q1.push((node){tp[j].u,tp[j].v,tp[j].w});
			}
			ss+=cst;
			lst=tmp2-cst;
		}
	}
	q2=q1;
	cout<<kr()+ss;
	return 0;
} 