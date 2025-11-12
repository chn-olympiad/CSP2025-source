#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2145145;
int _,n,m,k,t,a[N],b[N],ans,cnt,tot,op[N];
bool f,vis[N];
struct mb{
	int x,y,z;
	int mx,md,mn;
}p[N];
void solve(){
	a[1]=0;
	a[2]=0;
	a[3]=0;
	ans=0;
	cin>>n;
	tot=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y>>p[i].z;
		if(p[i].x>=p[i].y&&p[i].x>=p[i].z){
			p[i].mx=1;
			if(p[i].y>=p[i].z){
				p[i].mn=3;
				p[i].md=2;
			}
			else{
				p[i].md=3;
				p[i].mn=2;
			}
		}
		else if(p[i].y>=p[i].x&&p[i].y>=p[i].z){
			p[i].mx=2;
			if(p[i].x>=p[i].z){
				p[i].mn=3;
				p[i].md=1;
			}
			else{
				p[i].md=3;
				p[i].mn=1;
			}
		}
		else{
			p[i].mx=3;
			if(p[i].x>=p[i].y){
				p[i].mn=2;
				p[i].md=1;
			}
			else{
				p[i].md=2;
				p[i].mn=1;
			}
		}
		a[p[i].mx]++;
		ans+=max(p[i].x,max(p[i].y,p[i].z));
	}
	if(a[1]>n/2){
		for(int i=1;i<=n;i++){
			if(p[i].mx==1){
				if(p[i].md==2){
					op[++tot]=p[i].x-p[i].y; 
				}
				else{
					op[++tot]=p[i].x-p[i].z; 
				}
			} 
		}
	}
	else if(a[2]>n/2){
		for(int i=1;i<=n;i++){
			if(p[i].mx==2){
				if(p[i].md==1){
					op[++tot]=p[i].y-p[i].x; 
				}
				else{
					op[++tot]=p[i].y-p[i].z; 
				}
			} 
		}
	}
	else if(a[3]>n/2){
		for(int i=1;i<=n;i++){
			if(p[i].mx==3){
				if(p[i].md==1){
					op[++tot]=p[i].z-p[i].x; 
				}
				else{
					op[++tot]=p[i].z-p[i].y; 
				}
			} 
		}
	}
	else{
		cout<<ans<<"\n";
		return ;
	}
	sort(op+1,op+tot+1);
	for(int i=1;i<=max(a[1],max(a[2],a[3]))-n/2;i++){
		ans-=op[i];
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>_;
	while(_--){
		solve();
	}
	return 0; 
}
