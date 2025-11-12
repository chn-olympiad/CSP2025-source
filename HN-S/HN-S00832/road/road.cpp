#include<bits/stdc++.h>
using namespace std;
int qq[10005],ans,book[11],siz[1000005],fa[1000005];
long long answer=LONG_LONG_MAX;
struct stu
{
	int x,y,z;
}a[1000105],b[11][10005],c[100005];//n*k 
int cmp(stu x,stu y)
{
	return x.z<y.z;
}
__inline__ int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
__inline__ void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(siz[fx]>siz[fy])
		swap(x,y);
	siz[fy]+=siz[fx];
	fa[fx]=fy;
}
main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k; 
	for(int i=1;i<=m;++i)
		cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;++i)
	{
		cin>>qq[i];
		for(int j=1;j<=n;++j)
		{
			int x;
			cin>>x;
			c[j]={i+n,j,x};//因为你既然选了他，那么就一定会用它来连边，所以，他一定在这些图里
		}
		sort(c+1,c+1+n,cmp);
		for(int j=1;j<=n;++j)
			b[i][j]=c[j];
	}
	sort(a+1,a+1+m,cmp);
//	for(int i=1;i<=n;++i)
//	{
//		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n"; 
//	}
	for(int idx=0;idx<(1<<k);++idx)//时间复杂度 O(2^k*n*k*log(n*k)+m); 爆炸了 
	{//现在写的这种的时间复杂度为O(2^k*m) 1e9 需要卡常 
		long long ans=0,xxx=0;
		for(int i=1;i<=n+k;++i)
			fa[i]=i,siz[i]=1;
		for(int i=0;i<=k;++i)
			book[i]=1;
		vector<int>q; 
		for(int i=0;i<k;++i)
		{
			if((idx&(1<<i))==(1<<i))
			{
				ans+=qq[i+1];
				q.push_back(i+1);
				xxx++;
			}
		}
		int t=n-1+xxx;
		while(t--)
		{
			while(book[0]<=m&&find(a[book[0]].x)==find(a[book[0]].y)) 
				book[0]++;
			int sum=a[book[0]].z,xx=a[book[0]].x,yy=a[book[0]].y,qaq=0;
			if(book[0]>m)
				sum=INT_MAX,xx=0,yy=0;
			for(auto x:q)
			{
				if(book[x]>n)
					continue;
				while(find(b[x][book[x]].x)==find(b[x][book[x]].y)) 
					book[x]++;
				if(sum>b[x][book[x]].z)
					sum=b[x][book[x]].z,xx=b[x][book[x]].x,yy=b[x][book[x]].y,qaq=x;
			}
			ans+=sum;
			book[qaq]++;
//			cout<<xx<<" "<<yy<<"\n";
			merge(xx,yy);
//			cout<<xx<<" "<<yy<<" "<<sum<<"\n";
		}
		answer=min(ans,answer);
//		sort(a+1,a+1+cnt,cmp);//这么写是错误的，因为m已经拍过一遍了 
//		sort(b+1,b+1+cnt,cmp);//我们只需要单独排一遍新的就可以了 我们发现炸掉了 
//		for()我们决定预处理 
	}//空间复杂度O(k*n+m)==1e5+1e6; 
	//考虑替换每一条可以替换的边
	cout<<answer; 
//	cout<<(sizeof(a)+sizeof(b));
    return 0;
}//137MB
/*
5 6
1 2 3
1 3 4
2 3 4
2 4 5
2 5 6
4 5 3
4 2 1 3 2 3
2 3 3 4 4 3

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/ 
