#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

namespace kanade
{
	int read()
	{
		int ans=0,bs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')bs*=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans*bs;
	}
	
	int bcj[300010],sz[300010],T[300010],minn[300010][20];
	int val[30][300010],val2[30][300010],C[30];
	int find(int x)
	{
		if(x==bcj[x])return x;
		return bcj[x]=find(bcj[x]);
	}
	
	struct edge
	{
		int a,b;
		ll v,t;
	}e[3000010];
	int n,m,k;
	
	bool cmp(edge a,edge b)
	{
		return a.v<b.v;
	}
	
	
	void sol() 
	{
		ll ans=0;
		int w=1;
		for(int i=1;i<=k;i++)
		{
			ans=0;
			for(int j=1;j<=n;j++)
			{
				bcj[j]=j;
				sz[j]=1;
				minn[j][i]=j; 
			}
			sort(e+1,e+1+m,cmp);
			w=1;
			while(1)
			{
				int a=e[w].a,b=e[w].b;
				if(a>b)swap(a,b);
				int al=find(a),bl=find(b);
				if(al==bl)
				{
					w++;
					continue;
				}
				ll knd=e[w].v,pos=e[w].t;
				ll am=val[i][minn[al][i]],bm=val[i][minn[bl][i]];
				if(!T[i])am+=C[i];
				if(am+bm<knd)
				{
					knd=am+bm;
					pos=i;
				}
				T[pos]=1;
				//if(i==1)cout<<e[w].v<<' '<<am+bm<<endl;
				e[w].v=knd;
				e[w].t=pos;
				val[pos][minn[al][pos]]=val[pos][minn[bl][pos]]=0;
				
				ans+=e[w].v;
				if(sz[al]>sz[bl])swap(al,bl);
				bcj[al]=bl;
				sz[bl]+=sz[al];
				am=val[i][minn[al][i]],bm=val[i][minn[bl][i]];
				if(am<bm)minn[bl][i]=minn[al][i];

				if(sz[bl]==n)break;
				w++;
			}
		}
//		for(int i=1;i<=k;i++)
//		{
////			int tf=0;
////			for(int j=1;j<=m;j++)
////			{
////				if(e[j].t==i)tf=1;
////			}
////			if(!tf&&T[i])ans-=C[i];
//			T[i]=0;
//		}
//		for(int i=1;i<=k;i++)
//		{
//			ans=0;
//			for(int j=1;j<=n;j++)
//			{
//				bcj[j]=j;
//				sz[j]=1;
//				minn[j][i]=j; 
//			}
//			sort(e+1,e+1+m,cmp);
//			w=1;
//			while(1)
//			{
//				int a=e[w].a,b=e[w].b;
//				if(a>b)swap(a,b);
//				int al=find(a),bl=find(b);
//				if(al==bl)
//				{
//					w++;
//					continue;
//				}
//				ll knd=e[w].v,pos=e[w].t;
//				ll am=val2[i][minn[al][i]],bm=val2[i][minn[bl][i]];
//				if(!T[i])am+=C[i];
//				if(am+bm<knd)
//				{
//					knd=am+bm;
//					pos=i;
//				}
//				T[pos]=1;
//				//if(i==1)cout<<e[w].v<<' '<<am+bm<<endl;
//				e[w].v=knd;
//				e[w].t=pos;
//				val2[pos][minn[al][pos]]=val2[pos][minn[bl][pos]]=0;
//				
//				ans+=e[w].v;
//				if(sz[al]>sz[bl])swap(al,bl);
//				bcj[al]=bl;
//				sz[bl]+=sz[al];
//				am=val2[i][minn[al][i]],bm=val2[i][minn[bl][i]];
//				if(am<bm)minn[bl][i]=minn[al][i];
//
//				if(sz[bl]==n)break;
//				w++;
//			}
//		}
//		for(int i=1;i<=k;i++)
//		{
//			int tf=0;
//			for(int j=1;j<=m;j++)
//			{
//				if(e[j].t==i)tf=1;
//			}
//			if(!tf&&T[i])ans-=C[i];
//		}
		cout<<ans;
	}
	
	int main()
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
		{
			e[i].a=read(),e[i].b=read(),e[i].v=read();
		}
		for(int i=1;i<=k;i++)
		{
			C[i]=read();
			for(int j=1;j<=n;j++)
			{
				
				val2[i][j]=val[i][j]=read();
				//if(i==1&&val[i][j]<29111333)cout<<j<<endl;
			}
		}
		sol();
		return 0;
	}
}

int main()
{

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	kanade::main();
	return 0;
}
/*

*/

