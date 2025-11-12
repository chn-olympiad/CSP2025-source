#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}q[100005],a[100005],b[100005],c[100005];
int ta,tb,tc,td,d[100005];
bool cmp1(node x,node y){return x.x>y.x;}
bool cmp2(node x,node y){return x.y>y.y;}
bool cmp3(node x,node y){return x.z>y.z;}
bool cmp(int x,int y){return x>y;}
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;ta=tb=tc=td=0;
		for(int i=1;i<=n;i++){
			int maxn=0;
			cin>>q[i].x>>q[i].y>>q[i].z;
			maxn=max(max(q[i].x,q[i].y),q[i].z);
			if(maxn==q[i].x)
				a[++ta]=q[i];
			else if(maxn==q[i].y)
				b[++tb]=q[i];
			else c[++tc]=q[i];
		}
		sort(a+1,a+ta+1,cmp1),sort(b+1,b+tb+1,cmp2),sort(c+1,c+tc+1,cmp3);
		for(int i=1;i<=ta;i++)ans+=a[i].x;
		for(int i=1;i<=tb;i++)ans+=b[i].y;
		for(int i=1;i<=tc;i++)ans+=c[i].z;
		if(ta>n/2){
			for(int i=1;i<=ta;i++)
				d[i]=a[i].x-max(a[i].y,a[i].z);
			sort(d+1,d+ta+1,cmp);
			for(int i=n/2+1;i<=ta;i++)
				ans-=d[i];
		}
		if(tb>n/2){
			for(int i=1;i<=tb;i++)
				d[i]=b[i].y-max(b[i].x,b[i].z);
			sort(d+1,d+tb+1,cmp);
			for(int i=n/2+1;i<=tb;i++)
				ans-=d[i];
		}
		if(tc>n/2){
			for(int i=1;i<=tc;i++)
				d[i]=c[i].z-max(c[i].x,c[i].y);
			sort(d+1,d+tc+1,cmp);
			for(int i=n/2+1;i<=tc;i++)
				ans-=d[i];
		}
		cout<<ans<<"\n";
	}
}