#include<bits/stdc++.h>
using namespace std;
int ans,n,t,anss,re,tmax;
int s[100050];
struct node
{
	int a,b,c;
};
int aa,bb,cc;
node s1[100050];
bool cmp(const node&a,const node&b){
	return max(max(a.a,a.b),a.c)>max(max(b.a,b.b),b.c);
}
void bl()
{
	if(n==2)
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3&&i!=j;j++)
			{
				anss=0;
				if(i==1)anss+=s1[1].a;
				if(i==2)anss+=s1[1].b;
				if(i==3)anss+=s1[1].c;
				if(j==1)anss+=s1[2].a;
				if(j==2)anss+=s1[2].b;
				if(j==3)anss+=s1[2].c;
				ans=max(ans,anss);
			}
		}
	}
	else{
	sort(s1+1,s1+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		tmax=0;re=0;
		if(s1[i].a>tmax&&aa+1<=n/2)tmax=s1[i].a,re=1;
		if(s1[i].b>tmax&&bb+1<=n/2)tmax=s1[i].b,re=2;
		if(s1[i].c>tmax&&cc+1<=n/2)tmax=s1[i].c,re=3;
		ans+=tmax;
		if(re==1)aa++;
		if(re==2)bb++;
		if(re==3)cc++;
	}}
}
void px()
{
	for(int i=1;i<=n;i++)
	{
		s[s1[i].a]++;
	}
	int k=0;
	for(int i=20000;i>=0;i--)
	{
		while(s[i]>0&&k<n/2){
		k++;
		s[i]--;
		ans+=i;
		}
	} 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		aa=0,bb=0,cc=0;ans=0,anss=0,re=0,tmax=0;
		memset(s1,0,sizeof(s1));memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s1[i].a,&s1[i].b,&s1[i].c);
		}
		if(n<250)bl();
		else px();
		cout<<ans<<'\n';
	}
	return 0; 
} 
