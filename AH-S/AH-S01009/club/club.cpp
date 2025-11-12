#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],b[5]={0,0,0,0,0};
long long s=0;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++)
{
	cin>>n;
	s=0;
	for(int j=1;j<=n;j++)
	{
		a[j][4]=0;
	for(int k=1;k<=3;k++)
	{
		cin>>a[j][k];
		a[j][4]=max(a[j][4],a[j][k]);
	}
	if(a[j][1]==a[j][4])b[1]++;
	if(a[j][2]==a[j][4])b[2]++;
	if(a[j][3]==a[j][4])b[3]++;
    }
    //if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2)
    for(int k=1;k<=n;k++)s+=a[k][4];
    cout<<s<<endl;
}
return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int t,n,bbb[5]={0,0,0,0,0},tt;
long long s=0;
struct men
{
	int a,b,c,d,e,f,g,h;
}aaa[100005];
bool cmp1(men aa,men bb)
{
	return aa.g<bb.g;
}
bool cmp2(men cc,men dd)
{
	return cc.h<dd.h;
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++)
{
	cin>>n;
	s=0;
	for(int j=1;j<=n;j++)
	{
	cin>>aaa[j].a>>aaa[j].b>>aaa[j].c;
	if(aaa[j].a>aaa[j].b&&aaa[j].b>aaa[j].c)aaa[j].d=aaa[j].a,aaa[j].e=aaa[j].b,aaa[j].f=aaa[j].c;
	if(aaa[j].a>aaa[j].c&&aaa[j].c>aaa[j].b)aaa[j].d=aaa[j].a,aaa[j].e=aaa[j].c,aaa[j].f=aaa[j].b;
	if(aaa[j].b>aaa[j].a&&aaa[j].a>aaa[j].c)aaa[j].d=aaa[j].b,aaa[j].e=aaa[j].a,aaa[j].f=aaa[j].c;
	if(aaa[j].b>aaa[j].c&&aaa[j].c>aaa[j].a)aaa[j].d=aaa[j].b,aaa[j].e=aaa[j].c,aaa[j].f=aaa[j].a;
	if(aaa[j].c>aaa[j].b&&aaa[j].b>aaa[j].a)aaa[j].d=aaa[j].c,aaa[j].e=aaa[j].b,aaa[j].f=aaa[j].a;
	if(aaa[j].c>aaa[j].a&&aaa[j].a>aaa[j].b)aaa[j].d=aaa[j].c,aaa[j].e=aaa[j].a,aaa[j].f=aaa[j].b;
	aaa[j].g=aaa[j].d-aaa[j].e,aaa[j].h=aaa[j].e-aaa[j].f;
	if(aaa[j].a==aaa[j].d)bbb[1]++;
	if(aaa[j].b==aaa[j].d)bbb[2]++;
	if(aaa[j].c==aaa[j].d)bbb[3]++;
    }
    if(bbb[1]<=n/2&&bbb[2]<=n/2&&bbb[3]<=n/2)
    for(int j=1;j<=n;j++)s+=aaa[j].d;
    if(bbb[1]>n/2)
    {
		sort(aaa+1,aaa+1+n,cmp1);
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(aaa[j].d==aaa[j].a)s+=aaa[j].d,t++;
			if(t==n/2)
			{
				tt=j+1;
				break;
			}
	    }
	    for(int j=t;j<=n;j++)
	    if(aaa[j].d==aaa[j].a)
		{
			if(aaa[j].e==aaa[j].b)aaa[j].d=aaa[j].e,aaa[j].e=aaa[j].f,bbb[2]++;
			else if(aaa[j].e==aaa[j].c)aaa[j].d=aaa[j].e,aaa[j].e=aaa[j].f,bbb[3]++;
		}
	}
	if(bbb[2]>n/2)
    {
		sort(aaa+1,aaa+1+n,cmp1);
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(aaa[j].d==aaa[j].b)s+=aaa[j].d,t++;
			if(t==n/2)
			{
				tt=j+1;
				break;
			}
	    }
	    for(int j=t;j<=n;j++)
	    if(aaa[j].d==aaa[j].a)
		{
			if(aaa[j].e==aaa[j].c)aaa[j].e=aaa[j].f,aaa[j].f=aaa[j].g,bbb[3]++;
			else if(aaa[j].e==aaa[j].a)aaa[j].e=aaa[j].f,aaa[j].f=aaa[j].e,bbb[1]++;
		}
	}
		if(bbb[3]>n/2)
    {
		sort(aaa+1,aaa+1+n,cmp1);
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(aaa[j].d==aaa[j].b)s+=aaa[j].d,t++;
			if(t==n/2)
			{
				tt=j+1;
				break;
			}
	    }
	    for(int j=t;j<=n;j++)
	    if(aaa[j].d==aaa[j].a)
		{
			if(aaa[j].e==aaa[j].a)aaa[j].d=aaa[j].e,aaa[j].e=aaa[j].f,bbb[1]++;
			else if(aaa[j].e==aaa[j].b)aaa[j].d=aaa[j].e,aaa[j].e=aaa[j].f,bbb[2]++;
		} 
	}
    cout<<s<<endl;
}
return 0;
}
*/
