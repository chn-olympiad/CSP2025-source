#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],aa,bb,cc,d,z,x;
long long ans;
void add(int &cnt,int x[])
{
	ans+=d;
	cnt++;
	x[cnt]=d-z;
}
void out(int &cnt,int x[])
{
	int m=cnt-n/2;
	if(m<1)
	{
		cout<<ans<<"\n";
		return ;
	}
	sort(x+1,x+cnt+1);
	for(int i=1;i<=m;i++) ans-=x[i];
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		int acnt=0,bcnt=0,ccnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>aa>>bb>>cc;
			d=aa;
			z=bb;
			x=cc;
			if(d<z) swap(d,z);
			if(z<x) swap(z,x);
			if(d<z) swap(d,z);
			if(d==aa) add(acnt,a);
			else if(d==bb) add(bcnt,b);
			else add(ccnt,c);
		}
		if(acnt>bcnt&&acnt>ccnt) out(acnt,a);
		else if(bcnt>acnt&&bcnt>ccnt) out(bcnt,b);
		else out(ccnt,c);
	}
	return 0;
}
