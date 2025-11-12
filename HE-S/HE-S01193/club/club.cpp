#include<bits/stdc++.h>
using namespace std;
int n;
struct no{
	int fir,sec,thi;
}a[100005];
int f[100005],s[100005],c[100005];
bool cmp1(int x,int y){
	int r1 = max(a[x].sec,a[x].thi),r2 = max(a[y].sec,a[y].thi);
	r1 = a[x].fir - r1,r2 = a[y].fir - r2;
	return r1 < r2;
}
bool cmp2(int x,int y){
	int r1 = max(a[x].fir,a[x].thi),r2 = max(a[y].fir,a[y].thi);
	r1 = a[x].sec - r1,r2 = a[y].sec - r2;
	return r1 < r2;
}
bool cmp3(int x,int y){
	int r1 = max(a[x].sec,a[x].fir),r2 = max(a[y].sec,a[y].fir);
	r1 = a[x].thi - r1,r2 = a[y].thi - r2;
	return r1 < r2;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		cin >> n;
		ans = 0;
		int tot1 = 0,tot2 = 0,tot3 = 0;
		for(int i = 1;i <= n;i ++){
			cin >> a[i].fir >> a[i].sec >> a[i].thi;
			if(a[i].fir >= a[i].sec && a[i].fir >= a[i].thi){
				f[++ tot1] = i;
			}
			else if(a[i].sec >= a[i].fir && a[i].sec >= a[i].thi){
				s[++ tot2] = i;
			}
			else{
				c[++ tot3] = i;
			}
		}
		if(tot1 > n / 2){
			int g = tot1 - n / 2;
			sort(f + 1,f + 1 + tot1,cmp1);
			for(int i = 1;i <= g;i ++){
				if(a[f[i]].sec > a[f[i]].thi)s[++ tot2] = f[i];
				else c[++ tot3] = f[i];
				f[i] = 0;
			}
		}
		else if(tot2 > n / 2){
			int g = tot2 - n / 2;
			sort(s + 1,s + 1 + tot2,cmp2);
			for(int i = 1;i <= g;i ++){
				if(a[s[i]].fir > a[s[i]].thi)f[++ tot1] = s[i];
				else c[++ tot3] = s[i];
				s[i] = 0;
			}
		}
		else if(tot3 > n / 2){
			int g = tot3 - n / 2;
			sort(c + 1,c + 1 + tot3,cmp3);
			for(int i = 1;i <= g;i ++){
				if(a[c[i]].fir > a[c[i]].sec)f[++ tot1] = c[i];
				else s[++ tot2] = c[i];
				c[i] = 0;
			}
		}
		a[0].fir = a[0].sec = a[0].thi = 0;
		for(int i = 1;i <= tot1;i ++){
			ans += a[f[i]].fir;
		}
		for(int i = 1;i <= tot2;i ++){
			ans += a[s[i]].sec;
		}
		for(int i = 1;i <= tot3;i ++){
			ans += a[c[i]].thi;
		}
		cout << ans << '\n';
	}
	return 0;
}
