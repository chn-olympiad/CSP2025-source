#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
typedef long long ll;
using namespace std;
const int N=1e5+91,G=5e2+9,inf=0x7fffffff;
/*struct node
{
	int nu,ren,df;
}a[N];
*/
struct nade
{
	int cho,get;
}ly[4];
struct nede
{
	int l,r;
}vis[4][N];
/*
struct nnde
{
	ll um,
};
* */
//int vis[N][4],top=N,plvis[4];
int zt[4],top[4],next[N];
int chos,lyy;
//nnde ssum[4];
int n,t;
//ll sum=0;
/*
bool cmp(node a,node b)
{
	return a.nu>b.nu;
}
* */
bool cmp1(nade a,nade b)
{
	return a.get>b.get;
}
bool cmp2(nede a,nede b)
{
	return a.l>b.l;
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	top[1]=1,top[2]=1,top[3]=1;
	cin>>t;
	while(t--)
	{
//		memset(vis,0,sizeof(vis));
//		memset(a,0,sizeof(a));
//		memset(plvis,0,sizeof(plvis));
		scanf("%d",&n);
//		int p=1,d=1;
		ll sum=0,f=0;
		memset(vis,0,sizeof(vis));
		memset(top,0,sizeof(top));
		f(i,1,n)
		{
//			scanf("%d",&a[i].nu);
//			cout<<"YongYou:"<<a[i].nu<<endl;
/*
			cin>>a[i].nu;
			a[i].ren=p;
			a[i].df=d;
			d++;
			if(d%4==0)
			{
				d=1;
				p++;
			}
//			cout<<endl<<"P:"<<p<<endl;
			*/
			f=0;
			f(j,1,3)
			{
				scanf("%d",&zt[j]);
				if(top[j]<=n/2)
				{
					ly[j].get=zt[j];
					ly[j].cho=j;
				}
				if(top[j]>n/2)
				{
					f=1;
					ly[j].get=zt[j]-vis[j][vis[j][top[j]-1].r].l;
//					if(next[j]+1>3) ly[j].get=zt[j]-vis[j][next][vis[j][top[j]-1].r].l;
//					else ly[j].get=zt[j]-vis[j][next][vis[j][top[j]-1].r].l+vis[j][next+1][vis[j][top[j]-1].r].l;
					ly[j].cho=j;
				}
			}
			memset(zt,0,sizeof(zt));
			memset(ly,0,sizeof(ly));
			sort(ly+1,ly+1+3,cmp1);
			chos=ly[1].cho,lyy=ly[1].get;
			if(ly[1].get>0 && top[chos]>n/2)
			{
				sum+=ly[1].get;
				cout<<"sum XuanLe"<<chos<<endl;
				f(i,1,3)
				{
					cout<<"SheTun "<<i<<" LyYi:";
					f(j,1,top[i]) cout<<vis[i][j].l<<" ";
					cout<<endl;
				}
				vis[chos][top[chos]-1].r=chos;
				sum-=vis[chos][vis[chos][top[chos]-1].r].l;
				vis[chos][top[chos]-1].l=lyy;
				sort(vis[chos],vis[chos]+top[chos],cmp2);
				top[chos]++;
			}
			else if(ly[1].get>0)
			{
				sum+=lyy;
				cout<<"sum XuanLe"<<chos<<endl;
				f(i,1,3)
				{
					cout<<"SheTun "<<i<<" LyYi:";
					f(j,1,top[i]) cout<<vis[i][j].l<<" ";
					cout<<endl;
				}
				vis[chos][top[chos]].r=chos;
				vis[chos][top[chos]].l=lyy;
				sort(vis[chos],vis[chos]+top[chos],cmp2);
				top[chos]++;
			}
		}
//		sort(a+1,a+1+n*3,cmp);
//		cout<<endl<<"TiaoShi:"<<endl;;
/*
		f(i,1,n*3)
		{
//			cout<<a[i].nu<<" "<<a[i].df<<" "<<a[i].ren<<" "<<endl;
			cout<<a[i].ren<<"QuGuoMei:"<<vis[a[i].ren]<<" "<<a[i].df<<"QuDeShuLiang:"<<plvis[a[i].df]<<"  sum=";
			if(vis[a[i].ren]==0 && plvis[a[i].df]<n/2)
			{
				sum+=a[i].nu;
				vis[a[i].ren]=1;
				plvis[a[i].df]++;
			}
			cout<<sum;
			cout<<" n/2="<<n/2<<endl;
		}
		f(i,1,n*3)
		{
			cout<<"Ren:"<<a[i].ren<<" "<<"df:"<<a[i].df<<" "<<"ManYi:"<<a[i].nu<<endl;
		}
		* */
		cout<<sum<<endl;
	}
	return 0;
}






















































