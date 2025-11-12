#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,aa[100005],aaxb=0;
struct aa{
	int a,b,c;
	bool x;
}a[100005];
void dfs(int sd,int ah,int bh,int ch,int aa,int bb,int cc)
{
	if(sd==n+1)
	{
		ans=max(ans,ah+bh+ch); 
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].x)continue;
		a[i].x=1;
		if(aa<n/2)dfs(sd+1,ah+a[i].a,bh,ch,aa+1,bb,cc);
		if(bb<n/2)dfs(sd+1,ah,bh+a[i].b,ch,aa,bb+1,cc);
		if(cc<n/2)dfs(sd+1,ah,bh,ch+a[i].c,aa,bb,cc+1);
		a[i].x=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		bool xx=1;
		int ans1=0;
		ans=0,aaxb=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			aa[++aaxb]=a[i].a;
			ans1+=a[i].a;
			if(a[i].b||a[i].c)xx=0;
		}
		if(xx)
		{
			sort(aa+1,aa+1+aaxb);
			for(int i=1;i<=n/2;i++)ans1-=aa[i];
			cout<<ans1<<"\n";
			continue;
		}
		dfs(1,0,0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
