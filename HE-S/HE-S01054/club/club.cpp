#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e5+5;
long long n,cnt1[N],cnt2[N],cnt3[N],a1,a2,a3,p1,p2,p3,ma;
long long ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		p1=0;p2=0;p3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			ma=max(a1,a2);
			ma=max(ma,a3);
			if(ma==a1){
				p1++;
				ans+=ma;
				cnt1[p1]=min(ma-a2,ma-a3);
				
			}
			else if(ma==a2){
				p2++;
				ans+=ma;
				cnt2[p2]=min(ma-a1,ma-a3);
				
			}
			else if(ma==a3){
				p3++;
				ans+=ma;
				cnt3[p3]=min(ma-a1,ma-a2);				
			}
		}
		if(p1<=(n/2) && p2<=(n/2) && p3<=(n/2)){
			cout<<ans<<endl;
			continue;
		}
		if(p1>(n/2)){
			sort(cnt1+1,cnt1+1+p1);
			for(int i=1;i<=p1;i++){
				ans-=cnt1[i];
				if((p1-i)<=n/2) break;
			}
			cout<<ans<<endl;
			continue;
		}
		if(p2>(n/2)){
			sort(cnt2+1,cnt2+1+p2);
			for(int i=1;i<=p2;i++){
				ans-=cnt2[i];
				if((p2-i)<=n/2) break;
			}
			cout<<ans<<endl;
			continue;
		}
		if(p3>(n/2)){
			sort(cnt3+1,cnt3+1+p3);
			for(int i=1;i<=p3;i++){
				ans-=cnt3[i];
				if((p3-i)<=n/2) break;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	
	return 0;
}
