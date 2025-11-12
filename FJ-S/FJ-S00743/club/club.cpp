#include<bits/stdc++.h>
using namespace std;
int a[200000],b[200000],c[200000];
struct node{
	int as,x,y,z;
}s[200000][4];
struct Node{
	int A,B,C,D;
}sp[200000];
bool cmp(Node p,Node q)
{
	return p.D>q.D;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		bool vis1=1,vis2=1;
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>sp[i].A>>sp[i].B>>sp[i].C;
			sp[i].D=max(sp[i].A,max(sp[i].B,sp[i].C));
			if((sp[i].B==0&&sp[i].B!=sp[i-1].B)||(sp[i].C==0&&sp[i].C!=sp[i-1].C))
			vis1=0;
			if(sp[i].C==0&&sp[i].C!=sp[i-1].C)
			vis2=0;
		}
		sort(sp+1,sp+n+1,cmp);
		if(vis2!=0)
		{
			for(int i=1;i<=n/2;i++)
			ans+=sp[i].D;
			cout<<ans<<endl;
			continue;
		}
		else
		{
			for(int i=1;i<=n/2;i++)
			ans+=sp[i].D;
			for(int i=n/2+1;i<=n;i++)
			{
				if(sp[i].D==sp[i].A)
				ans+=sp[i].B;
				else
				ans+=sp[i].A;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=sp[i].A;
			b[i]=sp[i].B;
			c[i]=sp[i].C;
		}
		for(int i=1;i<=n;i++)
		{
			s[i][1].as=s[i][1].x=s[i][1].y=s[i][1].z=0;
			s[i][2].as=s[i][2].x=s[i][2].y=s[i][2].z=0;
			s[i][3].as=s[i][3].x=s[i][3].y=s[i][3].z=0;
		}
		s[1][1].as=a[1],s[1][1].x=1;
		s[1][2].as=b[1],s[1][2].y=1;
		s[1][3].as=c[1],s[1][3].z=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(s[i][1].as<s[i-1][j].as+a[i]&&s[i-1][j].x+1<=n/2)
				{
					s[i][1].as=s[i-1][j].as+a[i];
					s[i][1].x=s[i-1][j].x+1;
				}
				if(s[i][2].as<s[i-1][j].as+a[i]&&s[i-1][j].y+1<=n/2)
				{
					s[i][2].as=s[i-1][j].as+b[i];
					s[i][2].y=s[i-1][j].y+1;
				}
				if(s[i][3].as<s[i-1][j].as+a[i]&&s[i-1][j].z+1<=n/2)
				{
					s[i][3].as=s[i-1][j].as+c[i];
					s[i][3].z=s[i-1][j].z+1;
				}
			}
		}
		cout<<max(s[n][1].as,max(s[n][2].as,s[n][3].as))<<endl;
	}
	return 0;
}
