#include<bits/stdc++.h>
using namespace std;
long long a,b,d,e,f,g;
struct b1
{
	long long a,b,c,d,e;
}c[1000000];
int b2(b1 a,b1 b)
{
	if(a.a==b.a)
		if(a.b==b.b)return a.c>b.c;
		else return a.b>b.b;
	else return a.a>b.a;
}
int main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;
		for(int j=1;j<=b;j++)
		{
			cin>>c[j].a>>c[j].b>>c[j].c;
		}
		sort(c+1,c+1+a,b2);
		for(int j=1;j<=b;j++)
		{
			cin>>
		for(int j=1;j<=b;j++)
		{
		    if(max(c[j].a,max(c[j].b,c[j].c))==c[j].a)
            {
                if(g<b/2)
                {
                    g++;c[j].d=-1;f+=c[j].a;
                }
                else
                {
					c[j].d=1;
				}
            }
            if(max(c[j].a,max(c[j].b,c[j].c))==c[j].b)
            {
                if(d<b/2)
                {
                    d++;
                    c[j].d=-1;
                    f+=c[j].b;
                }
                else
                {
					c[j].d=2;
				}
            }
            if(max(c[j].a,max(c[j].b,c[j].c))==c[j].c)
            {
                if(e<b/2)
                {
                    e++;c[j].d=-1;f+=c[j].c;
                }
                else
                {
					c[j].d=3;
				}
            }
		}
		for(int j=1;j<=b;j++)
		{
			if(c[j].d!=-1)
			{
				switch(c[j].d)
				{
					case 1:
					    if(max(c[j].b,c[j].c)==c[j].b)
                        {
                            if(d<b/2){ d++;c[j].e=-1;f+=c[j].b;}
                        }
                        if(max(c[j].b,c[j].c)==c[j].c)
                        {
                            if(e<b/2){ e++;c[j].e=-1;f+=c[j].c;}
                        }
					break;
					case 2:
					    if(max(c[j].a,c[j].c)==c[j].a)
                        {
                            if(g<b/2){ g++;c[j].e=-1;f+=c[j].a;}
                        }
                        if(max(c[j].a,c[j].c)==c[j].c)
                        {
                            if(e<b/2){ e++;c[j].e=-1;f+=c[j].c;}
                        }
					break;
					case 3:
					    if(max(c[j].a,c[j].b)==c[j].a)
                        {
                            if(g<b/2){ g++;c[j].e=-1;f+=c[j].a;}
                        }
                        if(max(c[j].a,c[j].b)==c[j].b)
                        {
                            if(d<b/2){ d++;c[j].e=-1;f+=c[j].b;}
                        }
					break;
                }
            }
        }
		for(int j=1;j<=b;j++)
		{
			if(c[j].e!=-1&&c[j].d!=-1)
			{
			    if(min(c[j].a,min(c[j].b,c[j].c))==c[j].a)
                {
                    g++;f+=c[j].a;
                }
                if(min(c[j].a,min(c[j].b,c[j].c))==c[j].b)
                {
                    d++;f+=c[j].b;
                }
                if(min(c[j].a,min(c[j].b,c[j].c))==c[j].c)
                {
                    e++;f+=c[j].c;
                }
			}
		}
		cout<<f<<"\n";
		for(int j=1;j<=b;j++)
		{
			c[j].d=0;
			c[j].e=0;
		}
		g=0;
		d=0;
		e=0;
		f=0;
	}
	return 0;
}
