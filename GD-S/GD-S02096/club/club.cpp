#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int T,n,a[N][4],b[N],ans,cnt1,cnt2,cnt3,maxx;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxx=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=maxx;
			if(maxx==a[i][1]) cnt1++;
			else if(maxx==a[i][2]) cnt2++;
			else cnt3++;
		}
		if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				b[i]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				if(b[i]<0) b[i]=inf;
			}
			sort(b+1,b+1+n);
			for(int i=1;i<=cnt1-n/2;i++){
				ans-=b[i];
			}
		}
		if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				b[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				if(b[i]<0) b[i]=inf;
			}
			sort(b+1,b+1+n);
			for(int i=1;i<=cnt2-n/2;i++){
				ans-=b[i];
			}
		}
		if(cnt3>n/2){
			for(int i=1;i<=n;i++){
				b[i]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				if(b[i]<0) b[i]=inf;
			}
			sort(b+1,b+1+n);
			for(int i=1;i<=cnt3-n/2;i++){
				ans-=b[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
