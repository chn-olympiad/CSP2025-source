#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c,aa,bb,cc;
}s[100010];
bool cma(node q,node w)
{
	if(q.aa==w.aa)return min(q.a-q.b,q.a-q.c)<min(w.a-w.b,w.a-w.c);
	return q.aa<w.aa;
}
bool cmb(node q,node w)
{
	if(q.bb==w.bb)return min(q.b-q.a,q.b-q.c)<min(w.b-w.a,w.b-w.c);
	return q.bb<w.bb;
}
bool cmc(node q,node w)
{
	if(q.cc==w.cc)return min(q.c-q.b,q.c-q.a)<min(w.c-w.b,w.c-w.a);
	return q.cc<w.cc;
}
void play()
{
	int n,af=0,bf=0,cf=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b>>s[i].c;
		int u=max(s[i].a,max(s[i].b,s[i].c));
		ans+=u;
		if(u==s[i].a)
		{
			af+=1;
			s[i].aa=1;
		}
		else if(u==s[i].b)
		{
			bf+=1;
			s[i].bb=2;
		}
		else 
		{
			cf+=1;
			s[i].cc=3;
		}
	}
	if(af>n/2)
	{
		sort(s+1,s+n+1,cma);
		for(int i=1;i<=af-n/2;i++)
			ans-=min(s[i].a-s[i].b,s[i].a-s[i].c);
	}
	if(bf>n/2)
	{
		sort(s+1,s+n+1,cmb);
		for(int i=1;i<=bf-n/2;i++)
			ans-=min(s[i].b-s[i].a,s[i].b-s[i].c);
	}
	if(cf>n/2)
	{
		sort(s+1,s+n+1,cmc);
		for(int i=1;i<=cf-n/2;i++)
			ans-=min(s[i].c-s[i].b,s[i].c-s[i].a);
	}
	cout<<ans<<endl;
	return;
 } 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin>>ttt;
	while(ttt--)
		play();	
	return 0;
 } 
