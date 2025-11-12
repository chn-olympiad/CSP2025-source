//GZ-S00323 六盘水市第四实验中学 王本贤
#include<bits/stdc++.h>
using namespace std;
int t=0,n=0;
struct gj{
	int bm1,bm2,bm3;
}a[100005];
int x=0,y=0,z=0;
int js=0;
int maxn[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=0,y=0,x=0;
		memset(a,0,sizeof(a));
		memset(maxn,0,sizeof(maxn));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].bm1>>a[i].bm2>>a[i].bm3;
		
			maxn[i]=max(max(a[i].bm1,a[i].bm2),a[i].bm3);
			
			if(maxn[i]==a[i].bm1) x++;
			else if(maxn[i]==a[i].bm2) y++;
			else if(maxn[i]==a[i].bm3) z++;
			if(n/2<x)
			{
				maxn[i]=max(a[i].bm2,a[i].bm3);
				x--;
				if(maxn[i]==a[i].bm2) y++;
				else if(maxn[i]==a[i].bm3) z++;
			}
			else if(n/2<y)
			{
				maxn[i]=max(a[i].bm1,a[i].bm3);
				y--;
				if(maxn[i]==a[i].bm1) x++;
				else if(maxn[i]==a[i].bm3) z++;
			}
			else if(n/2<z)
			{
				maxn[i]=max(a[i].bm1,a[i].bm2);
				y--;
				if(maxn[i]==a[i].bm1) x++;
				else if(maxn[i]==a[i].bm2) y++;
			}
		}
		js=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<maxn[j];
			}
			cout<<endl;
			js+=maxn[i];
		}
		cout<<js;
	}
	
	
	return 0;
}
