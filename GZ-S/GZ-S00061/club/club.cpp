//GZ-S00061 华东师范大学附属贵阳学校 刘睿羽
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
int wxxn;
ll n,s,t;
struct node {
	ll x,y,z;
} a[N];
struct edge {
	ll a,b;
} d[N];
ll vis[N][2],cha,ans;
ll vic[4];
struct hhh {
	ll a,b;
} ch[N];
bool cmp(hhh n1,hhh n2) {
	return n1.a<n2.a;
}
bool cmp2(edge n1,edge n2) {
	return n1.a<n2.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		memset(vic,0,sizeof(vic));
		scanf("%d",&n);
		ll aini=0;
		for (int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			ll f=max(a[i].x,max(a[i].y,a[i].z));
			vis[i][0]=f;
			if (f==a[i].x) vis[i][1]=1;
			else if(f==a[i].y) vis[i][1]=2;
			else vis[i][1]=3;
			aini+=f;
			vic[vis[i][1]]++;
		}
		ll cha;
		for (int m=1; m<=3; m++) {
			if (vic[m]>(n/2)) {
			    cha=vic[m]-n/2;
				ll t=0;
				for (int i=1; i<=n; i++) {
					if (vis[i][1]==m) {
						d[++t].a=vis[i][0];
						d[t].b=i;
					}
				}
			}

		}
		ans=0;
		sort(d+1,d+1+n,cmp2);
		for (int i=1; i<=n; i++) {
			int gz=d[i].b;
			if (vis[gz][1]==1) ans=max(a[gz].z,a[gz].y); 
			else if (vis[gz][1]==2) ans=max(a[gz].z,a[gz].x); 
			else ans=max(a[gz].x,a[gz].y); 
			ch[i].a=vis[gz][0]-ans;
			ch[i].b=gz;
		}
		sort(ch+1,ch+1+n,cmp);
		for (int i=1; i<=cha; i++) {
			ll gz=ch[i].b;
			aini-=vis[gz][0];
			if (vis[gz][1]==1) ans=max(a[gz].z,a[gz].y); 
			else if (vis[gz][1]==2) ans=max(a[gz].z,a[gz].x); 
			else ans=max(a[gz].x,a[gz].y); 
			aini+=ans;
		}
		cout<<aini<<endl;
	}
	return 0;
}
