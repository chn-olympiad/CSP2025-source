//GZ-S00099 贵阳市第一中学 周代岳
#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int ma[100005],mayu[100005];
int maxa[100005];
int find(int i){
	for(int j=0;j<100005;j++){
		if(mayu[j] == i){
			return j;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		for(int j=1;j<=n;j++){
			cin >> a[j][0] >> a[j][1] >> a[j][2];
			maxa[j] = max(max(a[j][0],a[j][1]),a[j][2]);
			if(maxa[j] == a[j][0]) ma[j] = 0;
			else if(maxa[j] == a[j][1]) ma[j] = 1;	 
			else ma[j] = 2;
			mayu[j] = maxa[j];
		}
		int f[3]={0,0,0},ans=0;
		sort(maxa,maxa+n);
		for(int j=1;j<=n;j++){
			int zb = find(maxa[j]);
			if(f[ma[j]] < n/2){
				ans+=maxa[j];
				f[ma[j]]++;
			}
			else{
				a[zb][ma[zb]] = 0;
				ans += max(max(a[j][0],a[j][1]),a[j][2]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
