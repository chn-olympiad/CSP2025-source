#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4];
int n;
int f(int m,int c1,int c2,int c3)
{
	if(m==n) {
		if(c1==0) 
		{
			if(c2==0)return a[n][3];
			if(c3==0) return a[n][2];
			else return max(a[n][2],a[n][3]);
		}
		if(c2==0) 
		{
			if(c3==0) return a[n][1];
			else return max(a[n][1],a[n][3]);
		}
		return max(a[n][1],a[n][2]);
	}
	int x=0,y=0,z=0;
	if(c1>0) x=a[m][1]+f(m+1,c1-1,c2,c3);
	if(c2>0) y=a[m][2]+f(m+1,c1,c2-1,c3);
	if(c3>0) z=a[m][3]+f(m+1,c1,c2,c3-1);
	return max(x,max(y,z));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		int k=n/2;
		int w=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]); 
			}	
			if(a[i][2]!=0||a[i][3]!=0) w=0;
		}
		if(w){
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
				{
					if(a[j][1]<a[j+1][1])swap(a[j][1],a[j+1][1]);
				}
				int ans=0;
			for(int i=1;i<=k;i++) ans+=a[i][1];
			cout<<ans<<endl;continue; 
			}
			
		int x=f(1,k,k,k);
		printf("%d\n",x);
	}
	return 0;
}
