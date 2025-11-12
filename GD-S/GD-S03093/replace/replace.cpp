#include<bits/stdc++.h>
using namespace std;
int n,q;
struct ll{
	int l,r;
	string x,y,xx,yy;
}a[400005];
ll b[400005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=0;
		cin>>a[i].x>>a[i].y;
		for(int j=0;j<a[i].x.size();j++)
			if(a[i].x[j]!=a[i].y[j])
			{
				l=j;
				break;
			}
		for(int j=a[i].x.size()-1;j>=0;j--)
			if(a[i].x[j]!=a[i].y[j])
			{
				r=j;
				break;
			}
		a[i].l=l;
		a[i].r=r;
		for(int j=l;j<=r;j++)
			a[i].xx=a[i].xx+a[i].x[j],a[i].yy=a[i].yy+a[i].y[j];
		
	}
	for(int i=1;i<=q;i++)
	{
		int l=0,r=0,ans=0;
		cin>>b[i].x>>b[i].y;
		for(int j=0;j<b[i].x.size();j++)
			if(b[i].x[j]!=b[i].y[j])
			{
				l=j;
				break;
			}
		for(int j=b[i].x.size()-1;j>=0;j--)
			if(b[i].x[j]!=b[i].y[j])
			{
				r=j;
				break;
			}
		for(int j=l;j<=r;j++)
			b[i].xx=b[i].xx+b[i].x[j],b[i].yy=b[i].yy+b[i].y[j];
		for(int j=1;j<=n;j++)
		{
			if(a[j].xx==b[i].xx&&a[j].yy==b[i].yy)
			{
				int fl=1;
				for(int k=0;k<a[j].x.size();k++)
					if(b[i].x[k+l-a[j].l]!=a[j].x[k])fl=0;
				for(int k=0;k<a[j].y.size();k++)
					if(b[i].y[k+l-a[j].l]!=a[j].y[k])fl=0;
				if(fl)ans++;
			}
			if(a[j].xx==b[i].yy&&a[j].yy==b[i].xx)
			{
				swap(b[i].yy,b[i].xx);
				int fl=1;
				for(int k=0;k<a[j].x.size();k++)
					if(b[i].x[k+l-a[j].l]!=a[j].x[k])fl=0;
				for(int k=0;k<a[j].y.size();k++)
					if(b[i].y[k+l-a[j].l]!=a[j].y[k])fl=0;
				if(fl)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
