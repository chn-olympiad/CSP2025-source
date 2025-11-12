//GZ-S00426 遵义市第四中学 赵振宇
#include<bits/stdc++.h>
using namespace std;
struct node {
	int a,b,c,id;
	int mx,mxid;
} mp[100001];
int t;
int n;
vector<node> v[4];
bool flag1=true;
bool flag2=true;
bool flag3=true;
long long ans;
queue<node> q;
bool cmp(node x,node y) {
	return x.mx>y.mx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&mp[i].a,&mp[i].b,&mp[i].c);
			mp[i].id=i;
			mp[i].mx=max(max(mp[i].a,mp[i].b),mp[i].c);
			if(mp[i].a>=mp[i].b&&mp[i].a>=mp[i].c)
				mp[i].mxid=1;
			if(mp[i].b>=mp[i].a&&mp[i].b>=mp[i].c)
				mp[i].mxid=2;
			if(mp[i].c>=mp[i].a&&mp[i].c>=mp[i].b)
				mp[i].mxid=3;
			if(mp[i].a!=0)
				flag1=false;
			if(mp[i].b!=0)
				flag2=false;
			if(mp[i].c!=0)
				flag3=false;
			q.push(mp[i]);
		}	
		if((flag1&&flag2)||(flag1&&flag3)||(flag2&&flag3)) {
			sort(mp+1,mp+n+1,cmp);
			for(int i=1; i<=n/2; i++) {
				ans+=mp[i].mx;
			}
			printf("%lld\n",ans);
		}
		else if(flag3)
		{
			int aa=0,bb=0;
			sort(mp+1,mp+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(mp[i].mxid==1)
				{
					if(aa<n/2)
					{
						ans+=mp[i].mx;
						aa++;
					}
					else
					{
						ans+=mp[i].b;
						bb++;
					}
						
				}
				else
				{
					if(bb<n/2)
					{
						ans+=mp[i].mx;
						bb++;
					}
					else
					{
						ans+=mp[i].a;
						aa++;
					}
						
				}
			}
			printf("%lld\n",ans);
		}
		else if(flag2)
		{
			int aa=0,cc=0;
			sort(mp+1,mp+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(mp[i].mxid==1)
				{
					if(aa<n/2)
					{
						ans+=mp[i].mx;
						aa++;
					}
					else
					{
						ans+=mp[i].c;
						cc++
					}
						
				}
				else
				{
					if(cc<n/2)
					{
						ans+=mp[i].mx;
						cc++;
					}
					else
					{
						ans+=mp[i].a;
						aa++;
					}
						
				}
			}
			printf("%lld\n",ans);
		}
		else if(flag1)
		{
			int cc=0,bb=0;
			sort(mp+1,mp+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(mp[i].mxid==2)
				{
					if(bb<n/2)
					{
						ans+=mp[i].mx;
						bb++;
					}	
					else
					{
						ans+=mp[i].c;
						cc++;
					}
						
				}
				else
				{
					if(cc<n/2)
					{
						ans+=mp[i].mx;
						cc++;
					}
					else
					{
						ans+=mp[i].b;
						bb++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
