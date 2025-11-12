#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,o,p,q,ans;
struct f{int x,y,z,s,t,u,from;};
f a[maxn];
bool cmp(f g,f h){
	if(g.s+h.t>g.t+h.s||g.s+h.u>g.u+h.s||g.s+h.t>g.u+h.s||g.s+h.u>g.t+h.s) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z; 
		}
		for(int i=1;i<=n;i++){
			a[i].s=max(a[i].x,max(a[i].y,a[i].z));
			a[i].u=min(a[i].x,min(a[i].y,a[i].z));
			a[i].t=a[i].x+a[i].y+a[i].z-a[i].s-a[i].u;
			if(a[i].s==a[i].x){
				o++;
			}
			if(a[i].s==a[i].y){
				p++;
			}
			if(a[i].s==a[i].z){
				q++;
			}
		}
		if(o>n/2){
			ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=a[i].x;
				else{
					ans+=max(a[i].y,a[i].z);
				}
			}
		}else if(p>n/2){
			ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=a[i].y;
				else{
					ans+=max(a[i].x,a[i].z);
				}
			}
		}else if(q>n/2){
			ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=a[i].z;
				else{
					ans+=max(a[i].x,a[i].y);
				}
			}
		}else{
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i].x,max(a[i].y,a[i].z));
			}
		}
		cout<<ans<<"\n";
	}
	
	return  0;
} 
