#include<bits/stdc++.h>
using namespace std;
struct A
{
	int i,j,v;
}a[500000];
int b[500000][5];
bool cmp(A x,A y)
{
	return x.v>y.v;
}
int bz[500000],num[500];
struct Q
{
	int key;
	bool operator <(const Q &h)const{
		return key>h.key;
	}
};
priority_queue<Q> q;
int col[500000];
int pls(int x,int y)
{
	int yu=(x+y)%3;
	if(yu==0) return 3;
	return yu;
}
int read()
{
	char ch=getchar();
	int v=1;
	while(!('0'<=ch&&ch<='9'))
	{
		if(ch=='-') v=-1;
		ch=getchar();
	}
	int x=0;
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*v;
}
void sol()
{
	while(!q.empty()) q.pop();
	int tmp=0;
	int n;
	scanf("%d",&n);
	num[1]=num[2]=num[3]=0;
	for(int i=1;i<=n;i++)
	{
		bz[i]=0;
		for(int j=1;j<=3;j++)
		{
			tmp++;
			a[tmp].i=i,a[tmp].j=j;
			int x=read();
			a[tmp].v=x;
			b[i][j]=a[tmp].v;
		}
	}
	sort(a+1,a+1+tmp,cmp);
	int ans=0;
	for(int i=1;i<=tmp;i++)
	{
		if(bz[a[i].i]) continue;
		num[a[i].j]++;
		bz[a[i].i]=1;
		col[a[i].i]=a[i].j;
		ans+=a[i].v;
	}
	int z=0;
	if(num[1]>n/2) z=1;
	if(num[2]>n/2) z=2;
	if(num[3]>n/2) z=3;
	if(!z)
	{
		printf("%d\n",ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int id=col[i];
		if(id==z)
		{
			if(b[i][id]-b[i][pls(id,1)]<b[i][id]-b[i][pls(id,2)])
			q.push({b[i][id]-b[i][pls(id,1)]});
			else
			q.push({b[i][id]-b[i][pls(id,2)]});
		}
	}
	for(int i=num[z];i>n/2;i--)
	{
		Q t=q.top();
		q.pop();
		ans-=t.key;
	}
	printf("%d\n",ans);
}
double cl;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cl=clock();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sol();
	}
//	cout<<clock()-cl; 
}
