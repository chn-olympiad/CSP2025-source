#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long t,n,ans,c,s,f[10];
struct node
{
	long long x,y,z,mx,mi,mix,id,iid;
}a[N];
bool cmp(node u,node v)
{
	return u.mi>v.mi;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		ans=0;
		c=0;
		s=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				a[i].mx=a[i].x;
				a[i].id=1;
				if(a[i].y>=a[i].z){
					a[i].mix=a[i].y;
					a[i].iid=2;
				}else{
					a[i].mix=a[i].z;
					a[i].iid=3;
				}
			}
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				a[i].mx=a[i].y;
				a[i].id=2;
				if(a[i].x>=a[i].z){
					a[i].mix=a[i].x;
					a[i].iid=1;
				}else{
					a[i].mix=a[i].z;
					a[i].iid=3;
				}
			}
			if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				a[i].mx=a[i].z;
				a[i].id=3;
				if(a[i].x>=a[i].y){
					a[i].mix=a[i].x;
					a[i].iid=1;
				}else{
					a[i].mix=a[i].y;
					a[i].iid=2;
				}
			}
			a[i].mi=a[i].mx-a[i].mix;
		}
		sort(a+1,a+n+1,cmp);
		for(long long i=1;i<=n;i++){
			if(f[a[i].id]<n/2){
				ans+=a[i].mx;
				f[a[i].id]++;
				if(f[a[i].id]==n/2){
					c=a[i].id,s=i+1;
					break;
				}
			}
		}
		if(s){
			for(long long i=s;i<=n;i++){
				if(a[i].id==c){
					ans+=a[i].mix;
					f[a[i].iid]++;
				}else{
					ans+=a[i].mx;
					f[a[i].id]++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
