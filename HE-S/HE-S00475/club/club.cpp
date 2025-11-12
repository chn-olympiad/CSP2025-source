#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;

struct Stu{
	int a1,a2,a3;
	int xz;
}s[100005];

bool cmp(Stu a,Stu b){
	if (a.a1==b.a1){
		return a.a2>b.a2;
	}
	return a.a1 > b.a1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){//csh
		cin >> n;
		int ans = 0;
		int cnt1 = 0,cnt2=0,cnt3=0;
		int state = 3;//3-A 2-B 1-C
		for (int i = 1;i<=n;i++){
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
			if (s[i].a2!=0) state = 2;
			if (s[i].a3!=0) state = 1;
			
		}	
		if (state == 3){
			sort(s+1,s+1+n,cmp);
			for (int i = 1;i<=n/2;i++){
				ans+=s[i].a1;
			}
			cout << ans << endl;
		}
		if (state == 2){
			sort(s+1,s+1+n,cmp);
			for (int i = 1;i<=n;i++){
				if (s[i].a1 > s[i].a2){
					cnt1++;
					ans+=s[i].a1;
					s[i].xz = 1;
				}else{
					cnt2++;
					ans+=s[i].a2;
					s[i].xz = 2;
				}
			}
			while(cnt1>n/2){
				int dis = 100000;
				int xz = -1;
				for (int i=1;i<=n;i++){
					if (s[i].xz == 1){
						if (s[i].a1 - s[i].a2 < dis){
							dis = s[i].a1 - s[i].a2;
							xz = i;
						}
					}
				}
				ans -= dis;
				s[xz].xz = 2;
				cnt1--;
			}
			while(cnt2>n/2){
				int dis = 100000;
				int xz = -1;
				for (int i=1;i<=n;i++){
					if (s[i].xz == 2){
						if (s[i].a2 - s[i].a1 < dis){
							dis = s[i].a2 - s[i].a1;
							xz = i;
						}
					}
				}
				ans -= dis;
				s[xz].xz = 1;
				cnt2--;
			}
			cout << ans << endl;
		}
		if (state==1){
			sort(s+1,s+1+n,cmp);
			for (int i = 1;i<=n;i++){
				if (s[i].a1 > s[i].a2){//
					if (s[i].a3 > s[i].a1){
						cnt3++;
						ans+=s[i].a3;
						s[i].xz = 3;
					}
					else{
						cnt1++;
						ans+=s[i].a1;
						s[i].xz = 1;
					}
					
				}else{
					if (s[i].a3 > s[i].a2){
						cnt3++;
						ans+=s[i].a3;
						s[i].xz = 3;
					}
					else{
						cnt2++;
						ans+=s[i].a2;
						s[i].xz = 2;
					}
				}
			}
			while(cnt1>n/2){
				int dis = 100000;
				int xz[3] = {-1,-1};
				for (int i=1;i<=n;i++){
					if (s[i].xz == 1){
						if (s[i].a1 - s[i].a2 < dis || s[i].a1 - s[i].a3 < dis){
							if (s[i].a1 - s[i].a2 < s[i].a1 - s[i].a3){
								dis = s[i].a1 - s[i].a2;
								xz[0] = i;
								xz[1] = 2;
							}else{
								dis = s[i].a1 - s[i].a3;
								xz[0] = i;
								xz[1] = 3;
							}
							
						}
					}
				}
				ans -= dis;
				s[xz[0]].xz = xz[1];
				cnt1--;
			}
			while(cnt2>n/2){
				int dis = 100000;
				int xz[3] = {-1,-1};
				for (int i=1;i<=n;i++){
					if (s[i].xz == 2){
						if (s[i].a2 - s[i].a1 < dis || s[i].a2 - s[i].a3 < dis){
							if (s[i].a2 - s[i].a1 < s[i].a2 - s[i].a3){
								dis = s[i].a2 - s[i].a1;
								xz[0] = i;
								xz[1] = 1;
							}else{
								dis = s[i].a2 - s[i].a3;
								xz[0] = i;
								xz[1] = 3;
							}
							
						}
					}
				}
				ans -= dis;
				s[xz[0]].xz = xz[1];
				cnt2--;
			}
			while(cnt3>n/2){
				int dis = 100000;
				int xz[3] = {-1,-1};
				for (int i=1;i<=n;i++){
					if (s[i].xz == 3){
						if (s[i].a3 - s[i].a2 < dis || s[i].a3 - s[i].a1 < dis){
							if (s[i].a3 - s[i].a2 < s[i].a3 - s[i].a1){
								dis = s[i].a3 - s[i].a2;
								xz[0] = i;
								xz[1] = 2;
							}else{
								dis = s[i].a3 - s[i].a1;
								xz[0] = i;
								xz[1] = 1;
							}
							
						}
					}
				}
				ans -= dis;
				s[xz[0]].xz = xz[1];
				cnt3--;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
