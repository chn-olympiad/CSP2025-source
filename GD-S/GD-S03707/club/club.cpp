#include<cstdio>
#include<cmath>
#include<algorithm> 
using namespace std;
const int N=1e5+5;
int T,n,ln,num[5],ans,f[202][102][102];
bool bz[N];
struct Node
{
	int id,cl,val;
}a[N][5],s[N*5];
void ms(int l,int r,int pos)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	ms(l,mid,pos),ms(mid+1,r,pos);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i][pos].val>a[j][pos].val)
		{
			s[k]=a[i][pos];
			i++;
		}
		else
		{
			s[k]=a[j][pos];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		s[k]=a[i][pos];
		i++,k++;
	}
	while(j<=r)
	{
		s[k]=a[j][pos];
		j++,k++;
	}
	for(int o=l;o<=r;o++)
		a[o][pos]=s[o];
	return ;
}
void dfs(int x,int num1,int num2,int num3,int sum)
{
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(num1+1<=n/2) dfs(x+1,num1+1,num2,num3,sum+a[x][1].val);
	if(num2+1<=n/2) dfs(x+1,num1,num2+1,num3,sum+a[x][2].val);
	if(num3+1<=n/2) dfs(x+1,num1,num2,num3+1,sum+a[x][3].val);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			bz[i]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
//				++ln;
				scanf("%d",&a[i][j].val);
				a[i][j].id=i,a[i][j].cl=j;
			}
		}
		if(n<=10)
		{
			ans=0;
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
			continue;
		}
		if(n<=200)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						if(j+k>i||(i-j-k)>n/2) continue;
						f[i][j][k]=0;
						if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1].val);
						if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2].val);
						if(i-j-k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3].val);
						if(i==n) ans=max(ans,f[i][j][k]);
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		bool sf=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][2].val||a[i][3].val)
			{
				sf=1;
				break;
			}
		}
		if(!sf)
		{
			ms(1,n,1);
			ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i][1].val;
			printf("%d\n",ans);
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][1].val;
			a[i][3].val=abs(a[i][1].val-a[i][2].val),a[i][3].id=a[i][2].val-a[i][1].val;
		}
		ms(1,n,3);
		int num1=0,num2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][3].id)
			{
				if(num1+1<=n/2) num1++;
				else num2++,ans+=a[i][3].id;
			}
			else
			{
				if(num2+1<=n/2) num2++,ans+=a[i][3].id;
				else num1++;
			}
		}
		printf("%d",ans);
//		ms(1,ln);
////		for(int i=1;i<=ln;i++)
////			printf("  %d %d %d\n",a[i].id,a[i].cl,a[i].val);
//		for(int i=1;i<=ln;i++)
//		{
//			if(bz[a[i].id]) continue;
//			if(num[a[i].cl]+1<=n/2)
//			{
//				bz[a[i].id]=1;
//				num[a[i].cl]++;
//				ans+=a[i].val;
//			}
//		}
//		printf("%d\n",ans);
	}
	return 0;
}
