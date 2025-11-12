#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5;
ll T,n,ans,x[N];
struct E{
	ll x,y,z;
	bool operator<(const E &o)const{return y-x<o.y-o.x;}
	bool operator>(const E &o)const{return z-x<o.z-o.x;}
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(a,0,sizeof a);
		cin>>n;
		bool B=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z)B=0;
		}if(n==2)ans=max({a[1].x+a[2].y,a[1].x+a[2].z,a[1].y+a[2].x,a[1].y+a[2].z,a[1].z+a[2].x,a[1].z+a[2].y});
		else if(B){
			sort(a+1,a+n+1);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++)ans+=a[i].y;
		}else{
			for(int i=1;i<=n;i++)x[i]=max(a[i].z-a[i].x,a[i].y-a[i].x);
			sort(x+1,x+n+1,greater<ll>());
			if(x[n/2]<0){
				for(int i=1;i<=n;i++)ans+=a[i].x;
				for(int i=1;i<=n/2;i++)ans+=x[i];
			}else{
				for(int i=1;i<=n;i++)x[i]=max(a[i].z-a[i].y,a[i].x-a[i].y);
				sort(x+1,x+n+1,greater<ll>());
				if(x[n/2]<0){
					for(int i=1;i<=n;i++)ans+=a[i].y;
					for(int i=1;i<=n/2;i++)ans+=x[i];
				}else{
					for(int i=1;i<=n;i++)x[i]=max(a[i].y-a[i].z,a[i].x-a[i].z);
					sort(x+1,x+n+1,greater<ll>());
					for(int i=1;i<=n;i++)ans+=a[i].z;
					for(int i=1;i<=n/2;i++)ans+=x[i];	
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
