#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5;
struct node{
	int x,y,z;
}a[N+5];
int n;
int p1[N+5],p2[N+5],p3[N+5];
int p1t,p2t,p3t;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		p1t=p2t=p3t=0;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		for(int i=1;i<=n;i++){
			int g=max(a[i].x,max(a[i].y,a[i].z)),h=min(a[i].x,min(a[i].y,a[i].z));
			int u=a[i].x+a[i].y+a[i].z-g-h;
			if(a[i].x==g)p1[++p1t]=g-u;
			else if(a[i].y==g)p2[++p2t]=g-u;
			else if(a[i].z==g)p3[++p3t]=g-u;
			ans+=g;
		}
		sort(p1+1,p1+p1t+1);
		sort(p2+1,p2+p2t+1);
		sort(p3+1,p3+p3t+1);
		if(p1t>n/2)for(int i=1;i<=p1t-n/2;i++)ans-=p1[i];
		if(p2t>n/2)for(int i=1;i<=p2t-n/2;i++)ans-=p2[i];
		if(p3t>n/2)for(int i=1;i<=p3t-n/2;i++)ans-=p3[i];
		cout<<ans<<endl;
	}
}
