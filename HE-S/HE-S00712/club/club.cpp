#include<bits/stdc++.h>
using namespace std;
struct E{
	int a,b,c;
};
int t,n,a[100005][4],t1[100005],d1[20005],t2[100005],d2[20005],t3[100005],d3[20005];
queue<E> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int p=1,x=0,y=0,z=0,x1=0,x2=0,y1=0,y2=0,z1=0,z2=0,ans=0,t11=1,d11=1,t22=1,d22=1,t33=1,d33=1;
		memset(t1,0,sizeof(t1)),memset(d1,0,sizeof(d1)),memset(t2,0,sizeof(t2)),memset(d2,0,sizeof(d2)),memset(t3,0,sizeof(t3)),memset(d3,0,sizeof(d3));
		q.push({a[p][1],a[p][2],a[p][3]});
		while(!q.empty()||p<=n){
			bool o=false,j=false;
			E e=q.front();
			q.pop();
			if(e.a>=e.b&&e.a>=e.c){
				t1[t11++]=e.a-max(e.b,e.c),d1[d11++]=p;
				if(x1==0) x1=t1[1],x2=d1[1];
				if(x<n/2) x++,ans+=e.a;
				else if(e.a-max(e.b,e.c)>x1){
					ans-=a[x2][1],ans+=e.a,q.push({a[x2][1],a[x2][2],a[x2][3]});
					for(int i=1;i<=t11;i++) if(t1[i]<x1) x1=t1[i],x2=d1[i];
				}
				else if(e.b>e.c){
					if(y<n/2) y++,ans+=e.b;
					else if(e.b-e.c>y1) ans-=a[y2][2],ans+=e.a,q.push({a[y2][1],a[y2][2],a[y2][3]});
					else ans+=e.c,z++;
				}
				else ans+=e.c,z++;
			}
			else if(e.b>=e.a&&e.b>=e.c){
				t2[t22++]=e.b-max(e.a,e.c),d2[d22++]=p;
				if(y1==0) y1=t2[1],y2=d2[1];
				if(y<n/2) y++,ans+=e.b;
				else if(e.b-max(e.a,e.c)>y1){
					ans-=a[y2][2],ans+=e.b,q.push({a[y2][1],a[y2][2],a[y2][3]});
					for(int i=1;i<=t22;i++) if(t2[i]<y1) y1=t2[i],y2=d2[i];
				}
				else if(e.a>e.c){
					if(x<n/2) x++,ans+=e.a;
					else if(e.a-e.c>x1) ans-=a[x2][1],q.push({a[x2][1],a[x2][2],a[x2][3]});
					else ans+=e.c,z++;
				}
				else ans+=e.c,z++;
			}
			else{
				t3[t33++]=e.c-max(e.b,e.a),d3[d33++]=p;
				if(z1==0) z1=t3[1],z2=d3[1];
				if(z<n/2) z++,ans+=e.c;
				else if(e.c-max(e.a,e.b)>z1){
					ans-=a[z2][3],ans+=e.c,q.push({a[z2][1],a[z2][2],a[z2][3]});
					for(int i=1;i<=t33;i++) if(t3[i]<x1) x1=t3[i],x2=d3[i];
				}
				else if(e.a>e.b){
					if(x<n/2) x++,ans+=e.a;
					else if(e.a-e.b>x1) ans-=a[x2][1],q.push({a[x2][1],a[x2][2],a[x2][3]});
					else ans+=e.b,y++;
				}
				else ans+=e.b,y++;
			}
			if(p++<n) q.push({a[p][1],a[p][2],a[p][3]});
		}
		cout<<ans<<endl;
	}
	return 0;
}
