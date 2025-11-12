#include<bits/stdc++.h>
using namespace std;
struct tt{
	int x,s,who;
	int friend operator <(tt a,tt b){
		return a.x>b.x;
	}
}a[1000000];
int v[1000000],p,io,vv[1000],n,ans,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		p=0;ans=0;
		memset(v,0,sizeof v);
		memset(vv,0,sizeof vv);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[++p].x;
				a[p].s=j;a[p].who=i;
			}
		}
		io=n;
		sort(a+1,a+1+p);
		for(int i=1;i<=p;i++){
			if(v[a[i].who]==0&&vv[a[i].s]<n/2){
				v[a[i].who]=1;
				vv[a[i].s]++;
				ans+=a[i].x;
				io--;
			}
			if(io==0) break;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
