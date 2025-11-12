#include<bits/stdc++.h>
using namespace std;
long long int t,a,b=0,b1,b2,b3;
long long int c=0,d,e,f,g,h;
struct club
{
	int club1,club2,club3;
	
}x[1000010];
struct cb
{
	int cb1,cb2;
}y[10000010],z[1000010],w[10000010];

int cmp4(cb p,cb q)
{
	if(x[p.cb2].club1<=x[q.cb2].club1)
	{
		return true;
	}
	else if(x[p.cb2].club1==x[q.cb2].club1)
	{
		if(x[p.cb2].club2<=x[q.cb2].club2)
		{
			return true;
		}
		else if(x[p.cb2].club2==x[q.cb2].club2)
		{
			if(x[p.cb2].club3<=x[q.cb2].club3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int cmp5(cb p,cb q)
{
	if(x[p.cb2].club2<=x[q.cb2].club2)
	{
		return true;
	}
	else if(x[p.cb2].club2==x[q.cb2].club2)
	{
		if(x[p.cb2].club3<=x[q.cb2].club3)
		{
			return true;
		}
		else if(x[p.cb2].club3==x[q.cb2].club3)
		{
			if(x[p.cb2].club1<=x[q.cb2].club1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int cmp6(cb p,cb q)
{
	if(x[p.cb2].club3<=x[q.cb2].club3)
	{
		return true;
	}
	else if(x[p.cb2].club3==x[q.cb2].club3)
	{
		if(x[p.cb2].club1<=x[q.cb2].club1)
		{
			return true;
		}
		else if(x[p.cb2].club1==x[q.cb2].club1)
		{
			if(x[p.cb2].club2<=x[q.cb2].club2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int cmp1(cb p,cb q)
{
	if(p.cb1>=q.cb1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int cmp2(cb p,cb q)
{
	if(p.cb1>=q.cb1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int cmp3(cb p,cb q)
{
	if(p.cb1>=q.cb1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++)
	{
		cin>>a;
		b=a/2;
		b1=0;
		b2=0;
		b3=0;
		for(int i=0;i<a;i++)
		{
			cin>>x[i].club1>>x[i].club2>>x[i].club3;
		}
		for(int i=0;i<a;i++)
		{
			if(x[i].club1>=x[i].club2&&x[i].club1>=x[i].club3)
			{
				y[b1].cb1=x[i].club1;
				y[b1].cb2=i;
				b1=b1+1;
			}
			else if(x[i].club2>=x[i].club1&&x[i].club2>=x[i].club3)
			{
				z[b2].cb1=x[i].club2;
				z[b2].cb2=i;
				b2=b2+1;
			}
			else if(x[i].club3>=x[i].club1&&x[i].club3>=x[i].club1)
			{
				w[b3].cb1=x[i].club3;
				w[b3].cb2=i;
				b3=b3+1;
			}
		}
		if(b1>b)
		{
			sort(y,y+b1,cmp4);
			for(int i=b;i<b1;i++)
			{
				
				d=x[y[0].cb2].club1-x[y[0].cb2].club2;
				e=0;
				for(int j=1;j<b1;j++)
				{
					h=x[y[j].cb2].club1-x[y[j].cb2].club2;
					if(h<d)
					{
						d=h;
						e=j;
					}
				}
				f=x[y[0].cb2].club1-x[y[0].cb2].club3;
				g=0;
				for(int j=1;j<b1;j++)
				{
					h=x[y[j].cb2].club1-x[y[j].cb2].club3;
					if(h<f)
					{
						f=h;
						g=j;
					}
				}
				if(d>=f)
				{
					w[b2].cb1=x[y[e].cb2].club3;
					w[b2].cb2=y[g].cb2;
					b3=b3+1;
					y[g].cb1=0;
				}
				if(f>d)
				{
					z[b2].cb1=x[y[e].cb2].club2;
					z[b2].cb2=y[e].cb2;
					b2=b2+1;
					y[g].cb1=0;
				}
				sort(y,y+b1,cmp1);
				b1=b1-1;
				i=i-1;
			}
		}
		if(b2>b)
		{
			sort(z,z+b2,cmp5);
			for(int i=b;i<b2;i++)
			{
				d=x[z[0].cb2].club2-x[z[0].cb2].club3;
				e=0;
				for(int j=1;j<b2;j++)
				{
					h=x[z[j].cb2].club2-x[z[j].cb2].club3;
					if(h<d)
					{
						d=h;
						e=j;
					}
				}
				f=x[z[0].cb2].club2-x[z[0].cb2].club1;
				g=0;
				for(int j=1;j<b2;j++)
				{
					h=x[z[j].cb2].club2-x[z[j].cb2].club1;
					if(h<f)
					{
						f=h;
						g=j;
					}
				}
				if(d>=f)
				{
					y[b2].cb1=x[z[e].cb2].club1;
					y[b2].cb2=z[g].cb2;
					b1=b1+1;
					z[g].cb1=0;
				}
				if(f>d)
				{
					w[b2].cb1=x[z[e].cb2].club3;;
					w[b2].cb2=z[e].cb2;
					b3=b3+1;
					z[g].cb1=0;
					
				}
			sort(z,z+b2,cmp2);
			b2=b2-1;
			i=i-1;
			}
		}
		if(b3>b)
		{
			sort(w,w+b3,cmp6);
			for(int i=b;i<b2;i++)
			{
				d=x[w[0].cb2].club3-x[w[0].cb2].club1;
				e=0;
				for(int j=1;j<b3;j++)
				{
					h=x[w[0].cb2].club3-x[w[0].cb2].club1;
					if(h<d)
					{
						d=h;
						e=j;
					}
				}
				f=x[w[0].cb2].club3-x[w[0].cb2].club2;
				g=0;
				for(int j=1;j<b3;j++)
				{
					h=x[w[0].cb2].club3-x[w[0].cb2].club2;
					if(h<f)
					{
						f=h;
						g=j;
					}
				}
				if(d>=f)
				{
					z[b2].cb1=x[w[e].cb2].club2;
					z[b2].cb2=w[g].cb2;
					b2=b2+1;
					w[g].cb1=0;
				}
				if(f>d)
				{
					y[b2].cb1=x[w[e].cb2].club1;
					y[b2].cb2=w[e].cb2;
					b1=b1+1;
					w[g].cb1=0;
				}
				sort(w,w+b2,cmp3);
				b3=b3-1;
				i=i-1;
			}
		}
			c=0;
			for(int i=0;i<b1;i++)
			{
				c=c+y[i].cb1;
			}
			for(int i=0;i<b2;i++)
			{
				c=c+z[i].cb1;
			}
			for(int i=0;i<b3;i++)
			{
				c=c+w[i].cb1;
			}
			for(int i=0;i<b1;i++)
			{
				y[i].cb1=0;
			}
			for(int i=0;i<b2;i++)
			{
				z[i].cb1=0;
			}
			for(int i=0;i<b3;i++)
			{
				w[i].cb1=0;
			}
			cout<<c<<endl;
	}
	return 0;
}
