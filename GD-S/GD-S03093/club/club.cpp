#include<bits/stdc++.h>
using namespace std;
struct ll{
	int x,y,z,c1,c2,d1,d2,d3;
}a[500005];
ll b[500005];
int t,n;
bool cmp1(ll q,ll p){
	return q.c1>p.c1;
}
bool cmp2(ll q,ll p){
	return q.c2>p.c2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int s=0,x=0,y=0,z=0,k=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				a[i].d1=1;
				if(a[i].y>=a[i].z)a[i].c1=a[i].x-a[i].y,a[i].c2=a[i].y-a[i].z,a[i].d2=2,a[i].d3=3;
				else a[i].c1=a[i].x-a[i].z,a[i].c2=a[i].z-a[i].y,a[i].d2=3,a[i].d3=2;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				a[i].d1=2;
				if(a[i].x>=a[i].z)a[i].c1=a[i].y-a[i].x,a[i].c2=a[i].x-a[i].z,a[i].d2=1,a[i].d3=3;
				else a[i].c1=a[i].y-a[i].x,a[i].c2=a[i].z-a[i].x,a[i].d2=3,a[i].d3=1;
			}
			else
			{
				a[i].d1=3;
				if(a[i].x>=a[i].y)a[i].c1=a[i].z-a[i].x,a[i].c2=a[i].x-a[i].y,a[i].d2=1,a[i].d3=2;
				else a[i].c1=a[i].z-a[i].y,a[i].c2=a[i].y-a[i].x,a[i].d2=2,a[i].d3=1;
			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(a[i].d1==1)x++,s+=a[i].x;
			if(a[i].d1==2)y++,s+=a[i].y;
			if(a[i].d1==3)z++,s+=a[i].z;
			if(x>n/2)b[++k].c2=a[i].c2,b[k].d2=a[i].d2,b[k].d3=a[i].d3,x--,s-=a[i].x,b[k].x=a[i].x,b[k].y=a[i].y,b[k].z=a[k].z;
			if(y>n/2)b[++k].c2=a[i].c2,b[k].d2=a[i].d2,b[k].d3=a[i].d3,y--,s-=a[i].y,b[k].x=a[i].x,b[k].y=a[i].y,b[k].z=a[k].z;
			if(z>n/2)b[++k].c2=a[i].c2,b[k].d2=a[i].d2,b[k].d3=a[i].d3,z--,s-=a[i].z,b[k].x=a[i].x,b[k].y=a[i].y,b[k].z=a[k].z;		
		}
		sort(b+1,b+k+1,cmp2);
		for(int i=1;i<=k;i++)
		{
			if(b[i].d2==1)x++,s+=b[i].x;
			if(b[i].d2==2)y++,s+=b[i].y;
			if(b[i].d2==3)z++,s+=b[i].z;
			if(x>n/2)
			{
				x--,s-=b[i].d2;
				if(b[i].d3==2)s+=b[i].y;
				if(b[i].d3==3)s+=b[i].z;
			}
			if(y>n/2)
			{
				y--,s-=b[i].d2;
				if(b[i].d3==1)s+=b[i].x;
				if(b[i].d3==3)s+=b[i].z;
			}
			if(z>n/2)
			{
				z--,s-=b[i].d2;
				if(b[i].d3==2)s+=b[i].y;
				if(b[i].d3==1)s+=b[i].x;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
} 
