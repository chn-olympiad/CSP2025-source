#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int s;
int ba[100009],bb[100009],bc[100009];//people in bu men
int ka,kb,kc;//number of bu men
struct people
{
	int bm2;//second bu men
	int wm;//max
	int wc;//change
};people p[100009];
bool cmp(int x1,int x2)
{
	return p[x1].wc<p[x2].wc;
	};
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
for(int t=0;t<T;t++)
{
	
	//cin
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a>=b&&a>=c&&b>=c)
		{ p[i].bm2=1;p[i].wm=a;p[i].wc=a-b;
			ba[ka]=i;ka++;s+=a;
			}
		else if(a>=b&&a>=c&&c>=b)
		{ p[i].bm2=1;p[i].wm=a;p[i].wc=a-c;
			ba[ka]=i;ka++;s+=a;
			}		
		else if(b>=a&&b>=c&&a>=c)
		{ p[i].bm2=2;p[i].wm=b;p[i].wc=b-a;
			bb[kb]=i;kb++;s+=b;
			}	
		else if(b>=a&&b>=c&&c>=a)
		{ p[i].bm2=2;p[i].wm=b;p[i].wc=b-c;
			bb[kb]=i;kb++;s+=b;
			}
		else if(c>=a&&c>=b&&a>=b)
		{ p[i].bm2=3;p[i].wm=c;p[i].wc=c-a;
			bc[kc]=i;kc++;s+=c;
			}	
		else
		{ p[i].bm2=3;p[i].wm=c;p[i].wc=c-b;
			bc[kc]=i;kc++;s+=c;
			}
	}	
	//n/2 judge		
	if(ka>n/2)
	{
		sort(ba+0,ba+ka,cmp);
		for(int i=0;ka>n/2;i++)
		{
			int bm=p[ba[i]].bm2;
			if(bm==2)
			{
				bb[kb]=ba[i];kb++;ka--;s-=p[ba[i]].wc;
			}
			else
			{
				bc[kc]=ba[i];kc++;ka--;s-=p[ba[i]].wc;
			}
		}
	}
	if(kb>n/2)
	{
		sort(bb+0,bb+kb,cmp);
		for(int i=0;kb>n/2;i++)
		{
			int bm=p[bb[i]].bm2;
			if(bm==1)
			{
				ba[ka]=bb[i];ka++;kb--;s-=p[bb[i]].wc;
			}
			else
			{
				bc[kc]=bb[i];kc++;kb--;s-=p[bb[i]].wc;
			}
		}
	}
	if(kc>n/2)
	{
		sort(bc+0,bc+kc,cmp);
		for(int i=0;kc>n/2;i++)
		{
			int bm=p[bc[i]].bm2;
			if(bm==1)
			{
				ba[ka]=bc[i];ka++;kc--;s-=p[bc[i]].wc;
			}
			else
			{
				bb[kb]=bc[i];kb++;kc--;s-=p[bc[i]].wc;
			}
		}
	}

	cout<<s<<endl;
	memset(ba,0,sizeof(ba));
	memset(bb,0,sizeof(bb));
	memset(bc,0,sizeof(bc));
	memset(p,0,sizeof(p));
	s=0;ka=0;kb=0;kc=0;
}
	return 0;
}
