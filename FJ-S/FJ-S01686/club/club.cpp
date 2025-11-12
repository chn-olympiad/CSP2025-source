#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

struct node{
	int x,y,z;
}a[N];
struct cu{
	int w,c;
}cf[N],cs[N],ct[N];
int t,n,cntf,cnts,cntt;
long long ans;
bool cmp(cu j,cu k){
	return j.c>=k.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>t;
	while(t--){
		ans=0,cntf=0,cnts=0,cntt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z)
				cf[++cntf].w=a[i].x,cf[cntf].c=cf[cntf].w-max(a[i].z,a[i].y);
			else if(a[i].y>=a[i].x && a[i].y>=a[i].z)
				cs[++cnts].w=a[i].y,cs[cnts].c=cs[cnts].w-max(a[i].z,a[i].x);
			else if(a[i].z>=a[i].y && a[i].z>=a[i].x)
				ct[++cntt].w=a[i].z,ct[cntt].c=ct[cntt].w-max(a[i].x,a[i].y);
		}
		for(int i=1;i<=cntf;i++) ans+=cf[i].w;
		for(int i=1;i<=cnts;i++) ans+=cs[i].w;
		for(int i=1;i<=cntt;i++) ans+=ct[i].w;
		if(cntf>n/2){
			sort(cf+1,cf+cntf+1,cmp);
			for(int i=n/2+1;i<=cntf;i++){
				ans-=cf[i].c;
			}
		}else if(cnts>n/2){
			sort(cs+1,cs+cnts+1,cmp);
			for(int i=n/2+1;i<=cnts;i++){
				ans-=cs[i].c;
			}
		}else if(cntt>n/2){
			sort(ct+1,ct+cntt+1,cmp);
			for(int i=n/2+1;i<=cntt;i++){
				ans-=ct[i].c;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
