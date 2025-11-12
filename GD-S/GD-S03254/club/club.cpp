#include<algorithm>
#include<stdio.h>
#include<vector>
#define ll long long
#define N 100005

using namespace std;

ll rd() {
	char c=getchar(); ll x=0, y=1;
	while(!(c >= '0' && c <= '9' || c == '-')) c=getchar();
	if(c == '-') y=-1, c=getchar();
	while(c >= '0' && c <= '9') x=x*10+c-'0', c=getchar();
	return x*y;
}
int n;
int a[N][4], pos[N];
int c[4];
int lis[N], n1;
ll sum=0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int tt=rd();
	while(tt--) {
		n=rd(); n1=0;
		for(int j=1; j<=3; j++) c[j]=0;
		sum=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) a[i][j]=rd();
			int mx=-1; pos[i]=0;
			for(int j=1; j<=3; j++) {
				if(a[i][j] > mx) mx=a[i][j], pos[i]=j;
			}
			sum+=a[i][pos[i]], c[pos[i]]++;
		} 
		int err=0;
		for(int j=1; j<=3; j++) if(c[j] > n/2) err=j;
		if(!err) {printf("%lld\n", sum); continue;}
		for(int i=1; i<=n; i++) {
			if(pos[i] == err) {
				int mn = 1e9;
				for(int j=1; j<=3; j++) {
					if(j == pos[i]) continue;
					mn = min(mn, a[i][pos[i]]-a[i][j]);
				}
				lis[++n1]=mn;
			}
		}
		sort(lis+1, lis+n1+1);
		for(int i=1; i<=c[err]-n/2; i++) sum-=lis[i];
		printf("%lld\n", sum);
	}
	return 0;
}
