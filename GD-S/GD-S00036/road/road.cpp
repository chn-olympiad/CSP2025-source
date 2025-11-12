#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
long long n,m,k1,xx,yy,zz,sum=0,num=0,mink=0;
struct node{
	long long from,to,price;
}; 
node a[100051];
priority_queue<PII,vector<PII>,greater<PII> >number;
struct ab{
	long long to,price;
};
vector<int>numberx[10051];
long long k[11];
long long pricek[11];
long long p[11][100051];
long long fa[100051];
bool flag=false;
bool flagkp[10051];
void init(){
	for(int i=1;i<=n;i++) {
		fa[i]=i;
	}
	return ;
}
long long findx(long long x)
{
	if(fa[x]==x) return x;
	else return fa[x]=findx(fa[x]);
}
void hebin(long long x,long long y){
	long long u=findx(fa[x]),v=findx(fa[y]);
	fa[u]=v;
}
bool kp(node aa,node bb)
{
	return aa.price<bb.price;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k1;
	for(int i=1;i<=n;i++) {
		cin>>a[i].from>>a[i].to>>a[i].price;
	}init();
	
	for(int i=1;i<=k1;i++)
	{
		cin>>k[i];
		for(int j=1;j<=n;j++)
		{
			cin>>p[i][j];
			if(p[i][j]!=0) flag=true;
		}
	}
		sort(a+1,a+1+n,kp);
		for(int i=1;i<=n;i++)
		{
		long long u=findx(a[i].from),v=findx(a[i].to);
		//cout<<u<<" "<<v<<endl;
		if(u==v) continue;
		sum+=a[i].price;
		hebin(u,v);
		num++;
		if(num==n-1){
			break;
		}
		}
		mink=sum;
		//cout<<k1<<endl;
		for(int i=1;i<=k1;i++)
		{
			mink=min(mink,k[i]);
		}
		cout<<mink;

	return 0;
}
