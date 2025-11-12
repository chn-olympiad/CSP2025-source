#include <bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a,b,c;
}; 

bool cmd(node left,node right)
{
	int maxl=max(max(left.a,left.b),left.c);
	int maxr=max(max(right.a,right.b),right.c);
	return maxl>maxr;
}


int cida(int q,int e,int r)//¥Œ¥Û÷µ 
{
	int minn=min(min(q,e),r);
	int maxn=max(max(q,e),r);
	int he=q+e+r;
	int cha=he-minn-maxn;
	return cha;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int sum=0;
		node arr[100005];
		bool vis[100005];
		memset(vis,false,sizeof(vis));
		int n=0;
		scanf("%d",&n);
		int k=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
		}
		
		sort(arr+1,arr+1+n,cmd);
		int aa=0,bb=0,cc=0;
		int maxn=0,ci=0;
		int o=1;
		for(int i=1;i<=k;i++)
		{
			maxn+=max(arr[i].a,max(arr[i].b,arr[i].c));
			if(arr[i].a==maxn)
				aa++;
			if(arr[i].b==maxn)
				bb++;
			if(arr[i].c==maxn)
				cc++;
			cout<<"maxn="<<maxn<<"\n";
			vis[i]=true;
		}
		for(int i=1;i<=n;i++)
		{
			
			if(vis[o]==false)
			{
				
				if(aa-k==0 || bb-k==0 || cc-k==0)
				{
					ci+=cida(arr[i].a,arr[i].b,arr[i].c);
					continue;
				}
				
				ci+=max(arr[i].a,max(arr[i].b,arr[i].c));
			}
			o++;
			cout<<"ci="<<ci<<"\n";
		}
		sum=maxn+ci;
		cout<<sum<<"\n";
	}
	return 0;
}
