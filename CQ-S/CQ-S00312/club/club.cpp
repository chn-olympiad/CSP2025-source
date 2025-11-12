#include<bits/stdc++.h>
using namespace std;
struct zbczyx{
	int id,cx;
} a[100005],b[100005],c[100005];
int bj[100005],gogogo=0;
bool cmp(zbczyx c,zbczyx x)
{
	return c.cx>x.cx;
}
bool wcx(int n)
{
	for(int i=1;i<=gogogo;i++)
	{
		if(bj[i]==n) return 0;
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	int l;
	cin>>l;
	for(int j=1;j<=l;j++)
	{
		int n,maxx,ans=0,t1=0,t2=0,t3=0;
		gogogo=0; 
		cin>>n;
		maxx=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].cx>>b[i].cx>>c[i].cx;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int b1=0,b2=0,b3=0;
			if(t1>=maxx&&t2>=maxx&&t3>=maxx) break;
			if(a[i].id==b[i].id&&(t1<maxx||t2<maxx)&&wcx(a[i].id)&&wcx(b[i].id))
			{
				b1=1,b2=1;
				if(a[i].cx>b[i].cx)
				{
					if(t1==maxx)
					{
						t2++;
						ans+=b[i].cx;
						bj[++gogogo]=b[i].id;
					}
					else
					{
						t1++;
						ans+=a[i].cx;
						bj[++gogogo]=a[i].id;
					}
				}
				else
				{
					if(t2!=maxx)
					{
						t2++;
						ans+=b[i].cx;
						bj[++gogogo]=b[i].id;
					}
					else
					{
						t1++;
						ans+=a[i].cx;
						bj[++gogogo]=a[i].id;
					}
				}
			}
			else if(a[i].id==c[i].id&&(t1<maxx||t3<maxx)&&wcx(a[i].id)&&wcx(c[i].id))
			{
				b1=1,b3=1;
				if(a[i].cx>c[i].cx)
				{
					if(t1==maxx)
					{
						t3++;
						ans+=c[i].cx;
						bj[++gogogo]=c[i].id;
					}
					else
					{
						t1++;
						ans+=a[i].cx;
						bj[++gogogo]=a[i].id;
					}
				}
				else
				{
					if(t3!=maxx)
					{
						t3++;
						ans+=c[i].cx;
						bj[++gogogo]=c[i].id;
					}
					else
					{
						t1++;
						ans+=a[i].cx;
						bj[++gogogo]=a[i].id;
					}
				}
			}
			else if(c[i].id==b[i].id&&(t3<maxx||t2<maxx)&&wcx(c[i].id)&&wcx(b[i].id))
			{
				b2=1,b3=1;
				if(c[i].cx>b[i].cx)
				{
					if(t3==maxx)
					{
						t2++;
						ans+=b[i].cx;
						bj[++gogogo]=b[i].id;
					}
					else
					{
						t3++;
						ans+=c[i].cx;
						bj[++gogogo]=c[i].id;
					}
				}
				else
				{
					if(t2!=maxx)
					{
						t2++;
						ans+=b[i].cx;
						bj[++gogogo]=b[i].id;
					}
					else
					{
						t3++;
						ans+=c[i].cx;
						bj[++gogogo]=c[i].id;
					}
				}
			}
			if(t1<maxx&&wcx(a[i].id)&&!b1)
			{
				t1++;
				ans+=a[i].cx;
				bj[++gogogo]=a[i].id;
			}
			if(t2<maxx&&wcx(b[i].id)&&!b2)
			{
				t2++;
				ans+=b[i].cx;
				bj[++gogogo]=b[i].id;
			}
			if(t3<maxx&&wcx(c[i].id)&&!b3)
			{
				t3++;
				ans+=c[i].cx;
				bj[++gogogo]=c[i].id;
			}
		}
		cout<<ans<<endl;
	}
	//It is so nan,nan si me suan le.
	//Can ce ping ji give me 20 fen???
	//Pleace!!!
	//It is important for me!!!
	//Thank you! 
	return 0;
}
