#include <bits/stdc++.h>
using namespace std;
int ans0[100010];
struct node{
	int a,b,c;
	};
node A[1000010];
int maxxx(int a,int b,int c)
{
	return max(max(a,b),c);
}
bool cmp(node n1,node n2)
{
	return maxxx(n1.a,n1.b,n1.c)>maxxx(n2.a,n2.b,n2.c);
}
int cnt[100100];
//node tr[N<<2];

/*void upp(int k int l,int r int p,node v)
{
	if(l==p&&r==p)
	{
		tr[k]=v;
		return ;
	}
	int mid=l+((r-l)>>1);
	upp(k<<1,l,mid,p,v);
	upp(k<<1|1,mid+1,r,p,v);
	
}*/

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t=0,n=0;
	int maxn;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		n=0;
		int ans=0;

		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d %d %d",&A[j].a,&A[j].b,&A[j].c);
			
		}
//		for(int i=1;i<=n;i++)
	//	{
	//		node t=query(1,1,n,1,n);
			
	//	}
		
		sort(A+1,A+n+1,cmp);
	/*		for(int j=1;j<=n;j++)
		{
			printf("%d %d %d",A[j].a,A[j].b,A[j].c);
			cout<<endl;
			
		}*/

		
	
		for(int i=1;i<=n;i++)
		{
			int ma=-1,maxfo=0;
			
			if(cnt[1]+1<=n/2)
			{
				if(A[i].a>=ma)
				{
					if(A[i].a>ma)
					{
						
				
						maxfo=1;
						ma=A[i].a;
					}
				else 
				{
					if(cnt[1]<cnt[maxfo])
					{
						maxfo=1;
					}
				}	
			
			}
				
				
			
			}
			if(cnt[2]+1<=n/2)
			{
				if(A[i].b>=ma)
				{
					if(A[i].b>ma)
					{
						
					
						maxfo=2;
						ma=A[i].b;
					}
				
				
					else 
					{
						if(cnt[2]<cnt[maxfo])
						{
							maxfo=2;
						}
					}
				}
			}					
				
			
			if(cnt[3]+1<=n/2)
			{
				if(A[i].c>=ma)
				{
					if(A[i].c>ma)
					{
							maxfo=3;
						ma=A[i].c;
					}
				
				
				
		
					else 
					{
						if(cnt[3]<cnt[maxfo])
						{
							maxfo=3;
						}
					}
				}	
	}		

			ans+=ma;
			cnt[maxfo]++;
				}
			
			
		ans0[k]=ans;
		} 
		for(int i=1;i<=t;i++)
		{
			cout<<ans0[i];
			cout<<endl;
		}
			return 0;
	fclose(stdin);
	fclose(stdout);
		}
	

	

