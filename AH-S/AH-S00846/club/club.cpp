#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int d[100005],e1,e2,e3;
int n,t;
int f[100005],m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t; while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				d[i]=1; e1++; ans+=a[i][1];
			}else if(a[i][2]>=a[i][3]){
				d[i]=2; e2++; ans+=a[i][2];
			}else{
				d[i]=3; e3++; ans+=a[i][3];
			}
		}
		int k=0;
		if(e1>n/2) k=1;
		else if(e2>n/2) k=2;
		else k=3;
		if(k){
			for(int i=1;i<=n;i++) if(d[i]==k){
				f[++m]=a[i][k]-(a[i][1]+a[i][2]+a[i][3]-a[i][k]-min(a[i][1],min(a[i][2],a[i][3])));
			}
			sort(f+1,f+1+m);
			for(int i=1;i<=m-n/2;i++) ans-=f[i];
		}
		cout<<ans<<'\n';
		memset(a,0,sizeof(a)); memset(d,0,sizeof(d)); memset(f,0,sizeof(f)); n=e1=e2=e3=m=0;
	}
	return 0;
}