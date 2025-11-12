#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,a1[N][5],cnt[5],a2[N];
bool sta[N],flag;
long long ans;
struct Node{
	int id,c;
};
Node a[N],b[N],c[N];
bool cmp(Node da1,Node da2){
	return da1.c > da2.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		ans = 0;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= 3;j++) cin >> a1[i][j];
			if (a1[i][2] != 0||a1[i][3] != 0) flag = 1;
		}
		if (!flag){
			for (int i = 1;i <= n;i++) a2[i] = a1[i][1];
			sort(a2+1,a2+1+n);
			reverse(a2+1,a2+1+n);
			for (int i = 1;i <= n/2;i++) ans += a2[i];
			cout << ans << endl;
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		for (int i = 1;i <= n;i++){
			int maxn = -1,max1id,max2 = -1,max2id,max3 = -1,max3id;
			
			for (int j = 1;j <= 3;j++){
				if (a1[i][j] > maxn){
					maxn = a1[i][j];
					max1id = j;
				}
				else if (a1[i][j] > max2&&a1[i][j] <= maxn){
					max2 = a1[i][j];
					max2id = j;
				}
				else if (a1[i][j] > max3&&a1[i][j] <= max2){
					max3 = a1[i][j];
					max3id = j;
				}
			}
			
			//maxn = max(a1[i][1],max(a1[i][2],a1[i][3]));
			//max3 = min(a1[i][1],min(a1[i][2],a1[i][3]));

			if (cnt[max1id] < (n/2)) ans += maxn,cnt[max1id]++;
			else if (cnt[max2id] < (n/2)) ans += max2,cnt[max2id]++;
			else ans += max3,cnt[max3id]++;
		}
		cout << ans << endl;
	}
	return 0;
}
