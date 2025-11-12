#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n;
int ans;
int T;
int maxn[N];//i号员工最满意的 
int a[N],b[N],c[N];
int xa,xb,xc;
int maxn2[N];//i号员工第二满意的 
bool vis=false; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		int nn=n/2;
		xa=0,xb=0,xc=0;
		vis=false;
		for(int i=1;i<=n;i++){
			maxn[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			
		}
		for(int i=1;i<=n;i++){
			if(b[i]==0&&c[i]==0){
				vis=false;
			}else{
				vis=true;
				break;
			}
		}if(vis==false){
			sort(a+1,a+n+1);
			for(int i=n;i>nn;i--){
				ans+=a[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0&&c[i]==0){
				vis=false;
			}else{
				vis=true;
				break;
			}
		}if(vis==false){
			sort(b+1,b+n+1);
			for(int i=n;i>nn;i--){
				ans+=b[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0&&b[i]==0){
				vis=false;
			}else{
				vis=true;
				break;
			}
		}if(vis==false){
			sort(c+1,c+n+1);
			for(int i=n;i>nn;i--){
				ans+=c[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			maxn[i]=max(max(a[i],max(b[i],c[i])),maxn[i]);
			if(maxn[i]==a[i]){//i号员工最满意1部门 
				xa++;
				maxn2[i]=max(b[i],c[i]);
			}
			if(maxn[i]==b[i]){//最满意2号部门 
				xb++;
				maxn2[i]=max(a[i],c[i]);
			}
			if(maxn[i]==c[i]){//最满意3号部门 
				xc++;
				maxn2[i]=max(b[i],a[i]);
			}
			}if(xa<=nn&&xb<=nn&&xc<=nn){
				for(int i=1;i<=n;i++){
					ans+=maxn[i];
				}
				cout<<ans<<'\n';
				continue;
			}else{
				sort(maxn+1,maxn+n+1);
				for(int i=n;i>nn;i--){
					ans+=maxn[i];
				}for(int i=1;i<=nn;i++){
					ans+=maxn2[i];
				}
				cout<<ans<<'\n';
			}
	}
	return 0;
}
