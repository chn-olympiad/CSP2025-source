#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
struct node
{
	int num,xuhao;
	bool x;
}a[100500],b[100100],c[100100];
bool cmp(node x,node y){
	return x.num>y.num;
}
bool cmp1(node x,node y){
	return x.xuhao<y.xuhao;
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
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].xuhao=i;
			b[i].xuhao=i;
			c[i].xuhao=i;
			if(b[i].num!=0||c[i].num!=0)
				flag=false;
		}
		sort(a+1,a+n+1,cmp);
		if(flag)
		{
			for(int i=1;i<=n/2;i++)
				ans+=a[i].num;
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n/2;i++)
			a[i].x=1;
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			b[i].x=1;
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			c[i].x=1;
		sort(a+1,a+n+1,cmp1);
		sort(b+1,b+n+1,cmp1);
		sort(c+1,c+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			int maxx=0;
			if(a[i].x==1)
				maxx=max(maxx,a[i].num);
			if(b[i].x==1)
				maxx=max(maxx,b[i].num);
			if(c[i].x==1)
				maxx=max(maxx,c[i].num);
			ans+=maxx;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
