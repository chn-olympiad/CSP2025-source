#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int N=1e6+10;

ll n,m,k,ans;
struct Line 
{
	ll u1,u2;
	ll w;
	ll index;
}line[N];
ll lenth=0;
struct Node
{
	ll c;
	ll a[N];
	ll l;
}node[11];

bool cmp(Line a,Line b)
{
	if(a.w==b.w) 
	{
		if(a.u1==b.u1) return a.u2<b.u2;
		return a.u1<b.u1;
	}
	return a.w<b.w; 
}
void chuli(int i,int j)
{
	for(int k=1;k<=node[j].l;i++)
		if(line[i].index==j) 
			line[i].w-=node[j].c,k++;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool no[n+1];
	int quchong[n+1][n+1];
	memset(no,0,sizeof(no));
	memset(quchong,0,sizeof(quchong));
	for(int i=1;i<=m;i++) 
	{
		Line r;
		scanf("%lld %lld %lld",&r.u1,&r.u2,&r.w);
		if(quchong[r.u1][r.u2]!=0) 
			line[quchong[r.u1][r.u2]].w=min(line[quchong[r.u1][r.u2]].w,r.w);
		else line[++lenth]=r;
	}
	cout<<"1"; 
	for(int i=1;i<=k;i++) 
	{
		cin>>node[i].c;
		for(node[i].l=1;node[i].l<=n;node[i].l++) 
			cin>>node[i].a[node[i].l];	
 		node[i].l--;
 		for(int j=1;j<n;j++)
 			for(int l=j+1;l<=n;l++)
 				line[++lenth]={j,l,node[i].a[j]+node[i].a[l]+node[i].c,i};
	}
	sort(line+1,line+lenth+1,cmp);
	int i=0,j=1;
	while(i!=n-1)
	{
		if(no[line[j].u1]&&no[line[j].u2])
		{
			j++;
			continue;
		}
		ans+=line[j].w;
		no[line[j].u1]=1;
		no[line[j].u2]=1;
		i++;
		if(line[j].index!=0) chuli(j+1,line[j].index);
//		cout<<"line["<<j<<"].u1:"<<line[j].u1<<" "<<" line["<<j<<"].u2:"<<line[j].u2<<" line["<<j<<"].w:"<<line[j].w<<endl;
	}
	cout<<ans;
	return 0; 
}

