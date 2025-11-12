#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n;
int a,b,c;
int biao;
int pan[10];
long long ans;
struct node3{
	int maxn;
	int maxn2;
	int id;
};
node3 ren[N];
void cle()
{
	ans=0;
	pan[1]=pan[2]=pan[3]=0;
} 

bool cmp2(node3 x,node3 y)
{
	return x.maxn2<y.maxn2;
}
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		biao=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			ren[i].id=0;
			if(a>b&&a>c) 
			{
		    	ren[i].id=1;
				ren[i].maxn=a;
				ren[i].maxn2=max(b,c)-ren[i].maxn;	
			}else if(b>a&&b>c) 
			{
				ren[i].id=2;
				ren[i].maxn=b;
				ren[i].maxn2=max(a,c)-ren[i].maxn;	
			}else if(c>a&&c>b) 
			{
				ren[i].id=3;
				ren[i].maxn=c;
				ren[i].maxn2=max(b,a)-ren[i].maxn;	
			}else{
				ren[i].maxn=max(a,b);
				ren[i].maxn=max(ren[i].maxn,c);
				ren[i].maxn2=min(a,b)-ren[i].maxn2;
			}
			ans+=ren[i].maxn;
		//	cout<<"now="<<ans<<endl;
		}
		sort(ren+1,ren+1+n,cmp2);
		int allo=n+1;
		int ji=0;
		for(int i=1;i<=n;i++)
		{
			if(pan[ren[i].id]<biao) 
			{
				pan[ren[i].id]++;
			//	cout<<"pan"<<ren[i].id<<"="<<pan[ren[i].id]<<endl;
			}else{
				allo=i;
				ji=ren[i].id;
				i=n+1;
			}
		}
		for(int i=allo;i<=n;i++)
		{
		//	cout<<"maxn2"<<ren[i].maxn2<<endl;
		    if(ren[i].id==ji) ans+=ren[i].maxn2;
		 } 
			printf("%lld\n",ans);
			cle();
	}
	
	return 0;
}
