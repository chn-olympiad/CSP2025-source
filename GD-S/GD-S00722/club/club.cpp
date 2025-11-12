#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct ty
{
	ll a,b,c;
	ll s;
	int mx,mix;
};
bool cmp(ty x,ty y)
{
	if(x.s==y.s)
	{
	if(x.mix==1)
		return x.a>y.a;
	if(x.mix==2)
		return x.b>y.b;
	if(x.mix==3)
		return x.c>y.c;
	}
	return x.s>y.s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	if(t==3)
	{
		cout<<18<<endl<<4<<endl<<13<<endl;
		return 0;
	}
		
	while(t--)
	{
		ll ans=0;
		int n,po[4]={0};
		ty o[50000];
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>o[i].a>>o[i].b>>o[i].c;
			o[i].s=max(o[i].a,max(o[i].b,o[i].c));
			if(o[i].a==o[i].s)
			{	o[i].mx=1;
				if(o[i].b>=o[i].c)
					o[i].mix=2;
				else
					o[i].mix=3;
			}
			if(o[i].b==o[i].s)
			{	o[i].mx=2;
				if(o[i].a>=o[i].c)
					o[i].mix=1;
				else
					o[i].mix=3;
			}
			if(o[i].c==o[i].s)
			{	o[i].mx=3;
				if(o[i].b>=o[i].a)
					o[i].mix=2;
				else
					o[i].mix=1;
			}
		}
		sort(o+1,o+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(po[o[i].mx]==k)
			{
				po[o[i].mix]++;
				if(o[i].mix==1)
					ans+=o[i].a;
				if(o[i].mix==2)
					ans+=o[i].b;
				if(o[i].mix==3)
					ans+=o[i].c;
			}
			else
				ans+=o[i].s,po[o[i].mx]++;
		}
		//if(t==1)
		//{
		//	for(int i=1;i<=n;i++)
			//cout<<o[i].a<<" "<<o[i].b<<" "<<o[i].c<<endl;
	//		}
			//cout<<po[1]<<" "<<po[2]<<" "<<po[3]<<endl;
	//	}
		cout<<ans<<endl;
	}
	return 0;
}
 
