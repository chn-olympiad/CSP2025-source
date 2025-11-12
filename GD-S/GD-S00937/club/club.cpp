#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct stu
{
	int a,b,c;
	int cha;
};
vector<stu> st;
int maxa,maxb,maxc,n,ans;

void inint ()
{
	st.clear();
	maxa=maxb=maxc=n=ans=0;
}
void buildcha()
{
	if(maxa==max(max(maxa,maxb),maxc))//a
		for(int i=1;i<=n;i++)
			st[i].cha=min(st[i].a-st[i].b,st[i].a-st[i].c);
	else if(maxb==max(max(maxa,maxb),maxc))//b
		for(int i=1;i<=n;i++)
			st[i].cha=min(st[i].b-st[i].a,st[i].b-st[i].c);
	else if(maxc==max(max(maxa,maxb),maxc))//c
		for(int i=1;i<=n;i++)
			st[i].cha=min(st[i].c-st[i].a,st[i].c-st[i].b);
}
void so1(int f,int t)//不能算so2 其一不能选 
{
	for(int i=f;i<=t;i++)
	{
		ans+=max(max(st[i].a,st[i].b),st[i].c);
	}
}
void so2()
{
	buildcha();
	sort(st.begin(),st.end(),[](const stu &a,const stu &b)//注意大小st[0]=inf st[n+1]=-inf 
	{
		return a.cha>b.cha;
	});//由大到小
	for(int i=1;i<=n/2;i++)
	{
		if(maxa==max(max(maxa,maxb),maxc)) 		ans+=st[i].a;
		else if(maxb==max(max(maxa,maxb),maxc)) ans+=st[i].b;
		else if(maxc==max(max(maxa,maxb),maxc))	ans+=st[i].c;
	 } 
	for(int i=n/2+1;i<=n;i++)
	{
		if(maxa==max(max(maxa,maxb),maxc)) 		ans+=max(st[i].b,st[i].c);
		else if(maxb==max(max(maxa,maxb),maxc)) ans+=max(st[i].a,st[i].c);
		else if(maxc==max(max(maxa,maxb),maxc))	ans+=max(st[i].a,st[i].b);
	}
	
}
signed main ()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		inint();
		cin>>n;
		st.resize(n+5);
		
		st[0].cha=999999;
		for(int i=1;i<=n+4;i++)
		{
			st[i].cha=-999999;
		}
		
		for(int a,b,c,i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			if(a>=max(b,c))	maxa++;
			else if(b>=c) maxb++;
			else maxc++;
			st[i].a=a;
			st[i].b=b;
			st[i].c=c;
		}
		if(max(max(maxa,maxb),maxc)<=n/2)
			so1(1,n);
		else 
			so2();
		cout<<ans<<endl;
	}
	
	return 0;
}
