#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,d[N][4],bm[N][4],rs[N],xa,xb,xc,ans;
//struct person{
//	int a,b,c;
//} p[N];
int p[N][4],gz;
//bool cmp(int x[4],int y[4])
//{
//	if(x[gz]<y[gz])return 0;
//	else return 1;
//}
void dfs(int x,int an)
{
//	int myd[4];
	if(x==n+1){ans=max(ans,an);return;}
	for(int i=1;i<=n;i++)
	{
		if(rs[i]+1>n/2)continue;
		rs[i]++;
		dfs(x+1,an+p[x][i]);
		rs[i]--;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i][1]>>p[i][2]>>p[i][3];
		}
		dfs(1,0);/*
		gz=1;
		sort(p+1,p+1+n*3,cmp);
		for(int i=1;i<=n;i++)
		cout<<p[i][1]<<" "<<p[i][2]<<" "<<p[i][3]<<endl;
		cout<<endl;
		gz=2;sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
		cout<<p[i][1]<<" "<<p[i][2]<<" "<<p[i][3]<<endl;
		cout<<endl;
		gz=3;sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
		cout<<p[i][1]<<" "<<p[i][2]<<" "<<p[i][3]<<endl;
		cout<<endl;
		cout<<ans<<endl;
		
		d[1][1]=p[1][1];
		bm[1][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				xa=xb=xc=0;
				if(rs[1]+1<=n/2){
					xa=p[i][1];
				}
				if(rs[2]+1<=n/2){
					xb=p[i][2];
				}
				if(rs[3]+1<=n/2){
					xc=p[i][3];
				}
				if(xa>xb&&xa>xc)rs[1]++,printf("i:%d  j:%d  a\n",i,j);
				else if(xb>xa&&xb>xc)rs[2]++,printf("i:%d  j:%d  b\n",i,j);
				else rs[3]++,printf("i:%d  j:%d  c\n",i,j);
				d[i][j]=max(d[i][j-1],d[i-1][j-1]+max(xa,max(xb,xc)));
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<d[j][i]<<" ";
				ans=max(ans,d[j][i]);
			}
			cout<<endl;
		}*/
		//Õõ²»¶¯ÁË 
		cout<<ans<<endl;
	
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


18
4
13
*/
