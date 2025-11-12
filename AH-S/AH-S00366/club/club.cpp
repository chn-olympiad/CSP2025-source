#include<bits/stdc++.h>
using namespace std;
int t,ans;
int n,d[50005][3];
struct node{
	int num=0,id;
}a[50005],b[50005],c[50005];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
void check(int ax,int bx,int cx,int add)
{
	int mx=max(ax,max(bx,cx));
	if(mx==ax)
	{
		if(a[0].num+1<n/2)a[++a[0].num].num=ax,a[a[0].num].id=add;
		else
		{
			sort(a+1,a+a[0].num+1,cmp);
			if(a[a[0].num].num<ax)
			{
				int x=a[a[0].num].id;
				a[a[0].num].num=ax,a[a[0].num].id=add;
				check(0,d[x][1],d[x][2],x);
			}
			else check(0,d[add][1],d[add][2],add);
		}
	}
	if(mx==bx)
	{
		if(b[0].num+1<n/2)b[++b[0].num].num=bx,b[b[0].num].id=add;
		else
		{
			sort(b+1,b+b[0].num+1,cmp);
			if(b[b[0].num].num<bx)
			{
				int x=b[b[0].num].id;
				b[b[0].num].num=bx,b[b[0].num].id=add;
				check(d[x][0],0,d[x][2],x);
			}
			else check(d[add][0],0,d[add][2],add);
		}
	}
	if(mx==cx)
	{
		if(c[0].num+1<n/2)c[++c[0].num].num=cx,c[c[0].num].id=add;
		else
		{
			sort(c+1,c+c[0].num+1,cmp);
			if(c[c[0].num].num<cx)
			{
				int x=c[c[0].num].id;
				c[c[0].num].num=cx,c[c[0].num].id=add;
				check(d[x][0],d[x][1],0,x);
			}
			else check(d[add][0],d[add][1],0,add);
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qwq=1;qwq<=t;qwq++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i][0]>>d[i][1]>>d[i][2];
			check(d[i][0],d[i][1],d[i][2],i);
		}
		for(int i=1;i<=a[0].num||i<=b[0].num||i<=c[0].num;i++)
		{
			if(i<=a[0].num)ans+=a[i].num;
			if(i<=b[0].num)ans+=b[i].num;
			if(i<=c[0].num)ans+=c[i].num;
		}
		cout<<ans<<endl;
	}
	return 0;
}
