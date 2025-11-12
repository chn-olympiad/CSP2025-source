#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
	int maxx,minn,midd;
	int r1,r2,r3;
	int d; 
}k[maxn];
int cl[5],cnt;
struct no{
	int ne,ra;
}r[maxn];
bool cmp(node ll,node lll)
{
	if(ll.maxx!=lll.maxx) return ll.maxx>lll.maxx;
	if(ll.midd!=lll.midd) return ll.midd>lll.midd;
	return ll.minn>lll.minn;
}
bool cmp1(no A,no B)
{
	return A.ne>B.ne;
}
bool vi[maxn];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
		  int a,b,c;
		  cin>>a>>b>>c;
		  int ma=max(max(a,b),c);
		  int mi=min(min(a,b),c);
		  int md=a+b+c-ma-mi;
		  if(ma==a) k[i].r1=1;
		  else if(ma==b) k[i].r1=2;else if(ma==c) k[i].r1=3;
		  if(md==a) k[i].r2=1;
		  else if(md==b) k[i].r2=2;else  k[i].r2=3;
		  k[i].d=ma-md;
		  k[i].r3=1+2+3-k[i].r1-k[i].r2;
		 // cout<<ma<<" "<<md<<" "<<mi<<endl;
		 // cout<<k[i].r1<<" "<<k[i].r2<<" "<<k[i].r3<<endl;
		  k[i].maxx=ma;k[i].minn=mi;k[i].midd=md;

		}
		sort(k+1,k+n+1,cmp);
		//for(int i=1;i<=n;i++)
		//  cout<<k[i].maxx<<endl;
		int k1=0,k2=0,k3=0;
		for(int i=1;i<=n;i++)
		{
		  
		  if(k[i].r1==1) k1++;
		  else if(k[i].r1==2) k2++;
		  else k3++; 
		}
		//cout<<k1<<" "<<k2<<" "<<k3<<endl;
		if(k1>n/2||k2>n/2||k3>n/2)
		{    cnt=0; 
			memset(vi,0,sizeof(vi));
			int f;
			if(k1>n/2) f=1;
			else if(k2>n/2) f=2;
			else f=3;
			for(int i=1;i<=n;i++)
			{
			  if(k[i].r1==f)
			  {
			  	r[++cnt].ne=k[i].d;
			  	r[cnt].ra=i;
			  }
			 } 
			sort(r+1,r+cnt+1,cmp1);//cout<<cnt<<" ";
			//cout<<cnt-n/2<<endl;
			for(int i=1;i<=cnt-n/2;i++)
			{vi[r[i].ra]=1; 
			//cout<<r[i].ra<<endl;
			  }  
			for(int i=1;i<=n;i++)
			{
			  if(vi[i]||k[i].r1!=f) ans+=k[i].maxx;
			  else ans+=k[i].midd; 
			}
		}
		else{
			for(int i=1;i<=n;i++)
		{
		  if(cl[k[i].r1]>n/2)
		  {
              cl[k[i].r2]++;
              ans+=k[i].midd;
		  }
		  else
		  {
		  	cl[k[i].r1]++;
		  	ans+=k[i].maxx;
		  }
		}
		} 
		
		cout<<ans<<endl;
	}
	return 0;
 } 
 /* 3
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
¡¾ÑùÀý 1 Êä³ö¡¿*/
