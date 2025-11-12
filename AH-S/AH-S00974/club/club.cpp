#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int c1,c2,c3;
struct node{
	int x,y,z,m;
	int id;
}a[N],b[N];


bool cmp1(node a,node b){
	return a.x-a.y<b.x-b.y;
}

int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
   ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		int p=0;
		long long ans=0;
		memset(b,0,sizeof b);
		cin>>n;
		c1=c2=c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int mx=max(a[i].x,max(a[i].y,a[i].z));
			if(mx==a[i].x)  c1++,a[i].m=1;
			else if(mx==a[i].y) c2++,a[i].m=2;
			else c3++,a[i].m=3;
		}
		if(c1*2<=n&&c2*2<=n&&c3*2<=n){
			for(int i=1;i<=n;i++){
				ans+=max(a[i].x,max(a[i].y,a[i].z));
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c1*2>n){
			
			for(int i=1;i<=n;i++){
				if(a[i].m==1){
					b[++p].id=i;
					b[p].x=a[i].x;
					b[p].y=max(a[i].y,a[i].z);
				}
			}
			sort(b+1,b+1+p,cmp1);
			for(int i=1;i<=c1-n/2;i++){
				ans+=b[i].y;
			}
			for(int i=c1-n/2+1;i<=c1;i++){
				ans+=b[i].x;
			}
			for(int i=1;i<=n;i++){
				if(a[i].m!=1){
					if(a[i].m==2) ans+=a[i].y;
					else ans+=a[i].z;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(c2*2>n){
			for(int i=1;i<=n;i++){
				if(a[i].m==2){
					b[++p].id=i;
					b[p].x=a[i].y;
					b[p].y=max(a[i].x,a[i].z);
				}
			}
			sort(b+1,b+1+p,cmp1);
			for(int i=1;i<=c2-n/2;i++){
				ans+=b[i].y;
			}
			for(int i=c2-n/2+1;i<=c2;i++){
				ans+=b[i].x;
			}
			for(int i=1;i<=n;i++){
				if(a[i].m!=2){
					if(a[i].m==1) ans+=a[i].x;
					else ans+=a[i].z;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(c3*2>n){
			for(int i=1;i<=n;i++){
				if(a[i].m==3){
					b[++p].id=i;
					b[p].x=a[i].z;
					b[p].y=max(a[i].y,a[i].x);
				}
			}
			sort(b+1,b+1+p,cmp1);
			for(int i=1;i<=c3-n/2;i++){
				ans+=b[i].y;
			}
			for(int i=c3-n/2+1;i<=c3;i++){
				ans+=b[i].x;
			}
			for(int i=1;i<=n;i++){
				if(a[i].m!=3){
					if(a[i].m==2) ans+=a[i].y;
					else ans+=a[i].x;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
