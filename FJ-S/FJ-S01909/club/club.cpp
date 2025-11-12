#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int t,n;
long long ans = 0;
int cnt1 = 0,cnt2 = 0,cnt3 = 0;
int tt1[MAXN],tt2[MAXN],tt3[MAXN];
int main(){
	//freopen("club1.in","r",stdin);
	//freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 1;i <= n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			//cin >> x >> y >> z;
			int maxx = max(x,y),minn = 0;
			maxx = max(maxx,z);
			ans+=maxx;
			if(maxx == x){
				minn = min(x - y,x - z);
				cnt1++;
				tt1[cnt1] = minn;
			}else if(maxx == y){
				minn = min(y - x,y - z);
				cnt2++;
				tt2[cnt2] = minn;
			}else{
				minn = min(z - y,z - x);
				cnt3++;
				tt3[cnt3] = minn;
			}
		}	
		if(cnt1 > n/2){
			sort(tt1 + 1,tt1 + 1 + cnt1);
			for(int i = 1; i <= cnt1 - n / 2;i++) ans-=tt1[i];
		}else if(cnt2 > n / 2){
			sort(tt2 + 1,tt2 + 1 + cnt2);
			for(int i = 1; i <= cnt2 - n / 2;i++) ans-=tt2[i];
		}else if(cnt3 > n/2){
			sort(tt3 + 1,tt3 + 1 + cnt3);
			for(int i = 1; i <= cnt3 - n / 2;i++) ans-=tt3[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
