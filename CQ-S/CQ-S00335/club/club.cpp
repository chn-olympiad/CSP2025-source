#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll t,n,top;
struct opzc{
	ll x,y,z;	
}a[100005],cnt;
struct pz{
	ll x,y,z;
}zdz[100005];
bool cmp(pz a,pz b){
	return a.z<b.z; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cnt.x=cnt.y=cnt.z=0;
		top=0;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
			ans+=max({a[i].x,a[i].y,a[i].z});
			if(a[i].x>max(a[i].y,a[i].z)){
				cnt.x++;
			}else if(a[i].y>max(a[i].x,a[i].z)){
				cnt.y++;
			}else if(a[i].z>max(a[i].x,a[i].y)){
				cnt.z++;
			}
		}
		if(cnt.x>n/2){
			for(int i=1;i<=n;++i){
				if(a[i].x>max(a[i].y,a[i].z)){
					zdz[++top].z=a[i].x-max(a[i].y,a[i].z);
				}
			}
			sort(zdz+1,zdz+1+top,cmp);
			ll len=cnt.x-n/2;
			for(int i=1;i<=len;++i){
				ans-=zdz[i].z;
			}
		}else if(cnt.y>n/2){
			for(int i=1;i<=n;++i){
				if(a[i].y>max(a[i].x,a[i].z)){
					zdz[++top].z=a[i].y-max(a[i].x,a[i].z);
				}
			}
			sort(zdz+1,zdz+1+top,cmp);
			ll len=cnt.y-n/2;
			for(int i=1;i<=len;++i){
				ans-=zdz[i].z;
			}
		}else if(cnt.z>n/2){
			for(int i=1;i<=n;++i){
				if(a[i].z>max(a[i].x,a[i].y)){
					zdz[++top].z=a[i].z-max(a[i].x,a[i].y);
				}
			}
			sort(zdz+1,zdz+1+top,cmp);
			ll len=cnt.z-n/2;
			for(int i=1;i<=len;++i){
				ans-=zdz[i].z;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

