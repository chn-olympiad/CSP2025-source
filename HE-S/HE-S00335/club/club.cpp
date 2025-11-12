#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN][10];

int T,n;

int maax(int b,int c,int d){
	if(b > c&&b > d) return b;
	if(c > b&&c > d) return c;
	if(d > b&&d > c) return d;
}

int suo(int b,int c,int d){
	if(b == maax(b,c,d)) return 1;
	if(c == maax(b,c,d)) return 2;
	if(d == maax(b,c,d)) return 3;
}

int sd(int b,int c,int d){
	if(1 == suo(b,c,d)) return max(c,d);
	if(2 == suo(b,c,d)) return max(b,d);
	if(3 == suo(b,c,d)) return max(b,c);
}

int cha(int b){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			if(b == a[i][j]) return j;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T --){
		cin>>n;
		int ans = 0,cnt[5] = {0};
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) cin>>a[i][j];
		}
		for(int i = n;i >= 1;i--){
			if(cnt[suo(a[i][1],a[i][2],a[i][3])] + 1 <= n/2){
				ans += maax(a[i][1],a[i][2],a[i][3]);
				cnt[suo(a[i][1],a[i][2],a[i][3])] ++;
			} else {
				ans += sd(a[i][1],a[i][2],a[i][3]);
				cnt[cha(sd(a[i][1],a[i][2],a[i][3]))] ++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
