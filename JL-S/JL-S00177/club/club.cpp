#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][3],ans,d[3]{0};
int main(){
	cin>>t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	while(t--){
		ans=0;
		cin>>n;
		d[1]=d[2]=d[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==maxn && d[1]<=n/2){
				d[1]++;
				continue;
			}
			if(a[i][2]==maxn && d[2]<=n/2){
				d[2]++;
				continue;
			}
			if(a[i][3]==maxn && d[3]<=n/2){
				d[3]++;
				continue;
			}
			ans+=maxn;
		}
		cout<<ans<<endl;
	}
	return 0;
}
