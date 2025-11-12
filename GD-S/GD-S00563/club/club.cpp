#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100005][5],cnt[5],siz[5];
int d[5][200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)	
				cin>>a[i][j];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				ans+=a[i][1];
				d[1][++siz[1]]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				continue; 
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
				ans+=a[i][2];
				d[2][++siz[2]]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				continue;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				cnt[3]++;
				ans+=a[i][3];
				d[3][++siz[3]]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				continue;
			}
		}
		if(cnt[1]>n/2){
			sort(d[1]+1,d[1]+1+siz[1]);
			for(int i=1;cnt[1]>n/2;i++,cnt[1]--) ans-=d[1][i];
		}
		if(cnt[2]>n/2){
			sort(d[2]+1,d[2]+1+siz[2]);
			for(int i=1;cnt[2]>n/2;i++,cnt[2]--) ans-=d[2][i];
		}
		if(cnt[3]>n/2){
			sort(d[3]+1,d[3]+1+siz[3]);
			for(int i=1;cnt[3]>n/2;i++,cnt[3]--) ans-=d[3][i];
		}
		cout<<ans<<'\n';
		ans=cnt[1]=cnt[2]=cnt[3]=siz[1]=siz[2]=siz[3]=0;
	}
	return 0;
}
