#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t,n,v[N],x,y,z,w1,w2,w3,ans;
struct node{
	int w1,w2,w3;
}a[N],b[N],c[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{	
		x=y=z=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&w1,&w2,&w3);
			if(w1>=w2&&w1>=w3)a[++x]={w1,w2,w3},ans+=w1;
			else if(w2>=w1&&w2>=w3)b[++y]={w1,w2,w3},ans+=w2;
			else c[++z]={w1,w2,w3},ans+=w3;
		}
		if(x>n/2){
			for(int i=1;i<=x;i++)
			v[i]=a[i].w1-max(a[i].w2,a[i].w3);
			sort(v+1,v+x+1);
			for(int i=1;i<=x-n/2;i++)
			ans-=v[i];
		}
		if(y>n/2){
			for(int i=1;i<=y;i++)
			v[i]=b[i].w2-max(b[i].w1,b[i].w3);
			sort(v+1,v+y+1);
			for(int i=1;i<=y-n/2;i++)
			ans-=v[i];
		}
		if(z>n/2){
			for(int i=1;i<=z;i++)
			v[i]=c[i].w3-max(c[i].w1,c[i].w2);
			sort(v+1,v+z+1);
			for(int i=1;i<=z-n/2;i++)
			ans-=v[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
