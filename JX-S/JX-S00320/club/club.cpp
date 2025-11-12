#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
long long t,n,ans,pi,cnt=1;
struct k{
	int ip,w;
};
struct node{
	k x,y;
}a[N];
struct sc{
	int x,y;
}f[N];
long long vis[4],lll,sbr;
bool cmp(sc a,sc b){
	return a.x+b.y>a.y+b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			long long maxn=max(x,max(y,z)),maxc;
			lll=0,cnt=1;
			if(x==maxn){
				a[i].x.ip=1;
				vis[1]++;
				maxc=max(y,z);
				if(y==maxc){
					a[i].y.ip=2;
				}else{
					a[i].y.ip=3;
				}
			}else if(y==maxn){
				a[i].x.ip=2;
				vis[2]++;
				maxc=max(x,z);
				if(x==maxc){
					a[i].y.ip=1;
				}else{
					a[i].y.ip=3;
				}
			}else{
				a[i].x.ip=3;
				vis[3]++;
				maxc=max(x,y);
				if(x==maxc){
					a[i].y.ip=1;
				}else{
					a[i].y.ip=2;
				}
			}
			a[i].x.w=maxn,a[i].y.w=maxc;
			ans+=maxn;
		}
		for(int i=1;i<=3;i++){
			if(lll<=vis[i]){
				lll=vis[i];
				pi=i;
			}
		}
		if(lll*2<=n){
			cout<<ans<<endl;
		}else{
			long long res=0,curr=0;
			//cout<<pi<<endl;
			sbr=lll-n/2;	
			for(int i=1;i<=n;i++){
				if(a[i].x.ip==pi){
					f[cnt].x=a[i].x.w;
					f[cnt].y=a[i].y.w;
					res+=f[cnt].x;
					cnt++;
				}
			}		
			sort(f+1,f+1+lll,cmp);
			for(int i=1;i<=n/2;i++){
				curr+=f[i].x;
			}
			for(int i=n/2+1;i<=lll;i++){
				curr+=f[i].y;
			}
			cout<<ans+curr-res<<endl;
		}

		vis[1]=vis[2]=vis[3]=0;	
	}
}
