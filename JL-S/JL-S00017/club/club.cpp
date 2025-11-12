#include<bits/stdc++.h>
using namespace std;
struct club
{
	long long myd;
	bool xz;
	};
club ia[10000],ib[10000],ic[10000];
long long t,n,a_s,b_s,c_s,cs,bs;
int main()
{
//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);
cin>>t;
while(t--)
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ia[i].myd>>ib[i].myd>>ic[i].myd;//shu ru
	if(n==2&&ia[0].myd!=ia[1].myd&&ib[0].myd!=ib[1].myd&&ic[0].myd!=ic[1].myd)cout<<max(ia[0].myd,max(ib[0].myd,ic[0].myd));
	else if(n==2&&ia[0].myd==ia[1].myd)cout<<max(ib[0].myd,ib[1].myd)+max(ic[0].myd,ic[1].myd);
	else if(n==2&&ib[0].myd==ib[1].myd)cout<<max(ia[0].myd,ia[1].myd)+max(ic[0].myd,ic[1].myd);
	else if(n==2&&ic[0].myd==ic[1].myd)cout<<max(ib[0].myd,ib[1].myd)+max(ia[0].myd,ia[1].myd);
	else 
	{for(int i=0;i<n;i++)
	{
		if(ic[i].myd==ic[i+1].myd)cs==1; 
		if(ib[i].myd=ib[i+1].myd)bs==1; 
		} 
		if(cs==0&&bs==0)
		{
			for(int i=0;i<n;i++)
			a_s=max(a_s,ia[i].myd);
			cout<<a_s+ib[0].myd+ic[0].myd;
			}
			else if(cs==0)
			for(int i=0;i<n;i++)
			{
			a_s=max(a_s,ia[i].myd);
			b_s=max(b_s,ib[i].myd);
			}
			cout<<a_s+b_s+ic[0].myd;
		}
return 0;
}
}
