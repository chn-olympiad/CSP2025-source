#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,ma=0,p=0,o=0,w=0;
struct myd
{
	int x,y,z;
}a[1000000],b;
bool cmp(myd a,myd b)
{
	if(a.x==0||a.y==0||a.z==0)return 1;
	if(b.x==0||b.y==0||b.z==0)return 0;
	if(a.x>b.x)return 0;
	if(a.y>b.y)return 0;
	if(a.z>b.z)return 0;
	return 1;
	
}
/*void yo();
void zo();
void xo()
{
	p--;
	myd ll=b[0][p];
	int h;
	for(int i=p-1;i>=0;i--)if(b[0][i].x<ll.x)ll=b[0][i],h=i;
	b[0][h]=b[0][p];
	if(ll.y>ll.z)
	{
		b[1][o]=ll;
		ma=ll.y;
		if(o>n/2+1)yo();
	}
	else
	{
		b[2][w]=ll;
		ma=ll.z;
		if(w>n/2+1)zo();
	}
}
void yo()
{
	o--;
	myd ll=b[1][o];
	int h;
	for(int i=o-1;i>=0;i--)if(b[1][i].y<ll.y)ll=b[1][i],h=i;
	b[1][h]=b[1][o];
	if(ll.x>ll.z)
	{
		b[0][p]=ll;
		ma=ll.x;
		if(p>n/2+1)xo();
	}
	else
	{
		b[2][w]=ll;
		ma=ll.z;
		if(w>n/2+1)zo();
	}
}
void zo()
{
	w--;
	myd ll=b[2][w];
	int h;
	for(int i=w-1;i>=0;i--)if(b[2][i].z<ll.z)ll=b[2][i],h=i;
	b[2][h]=b[2][w];
	if(ll.x>ll.y)
	{
		b[0][p]=ll;
		ma=ll.x;
		if(p>n/2+1)xo();
	}
	else
	{
		b[1][o]=ll;
		ma=ll.y;
		if(o>n/2+1)yo();
	}
}
void bfs()
{
	int k;
	queue<myd>q;
	myd l;
	q.push(a[0]);
	while(k!=n)
	{
		l=q.front();
		q.pop();
		ma=max(max(l.x,l.y),l.z);
		if(ma=l.x)
		{
			b[0][p]=l;
			p++;
			if(p>n/2+1)xo();
		}
		if(ma=l.y)
		{
			b[1][o]=l;
			o++;
			if(o>n/2+1)yo();
		}
		if(ma=l.z)
		{
			b[2][w]=l;
			w++;
			if(w>n/2+1)zo();
		}
		ans+=ma;
		q.push(a[k]);
		k++;
	}
}*/
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++)
	{
		ans=0;
		b={0,0,0};
		cin>>n;
		for(int i=0;i<n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
//		bfs();
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			ma=max(max(a[i].x,a[i].y),a[i].z);
			if(ma==a[i].x)
			{
				b.x++;
				if(b.x>n/2)
				{
					b.x--;
					ma=max(a[i].y,a[i].z);
					if(ma==a[i].y)
					{
						b.y++;
						if(b.y>n/2)b.y--;
					}
					else b.z++,ma=a[i].z;
				}
			}
			else if(ma==a[i].y)
			{
				b.y++;
				if(b.y>n/2)
				{
					b.y--;
					ma=max(a[i].x,a[i].z);
					if(ma==a[i].x)
					{
						b.x++;
						if(b.x>n/2)b.x--;
					}
					else b.z++,ma=a[i].z;
				}
			}
			else b.z++;
			ans+=ma;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*3
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
4 0 0*/
