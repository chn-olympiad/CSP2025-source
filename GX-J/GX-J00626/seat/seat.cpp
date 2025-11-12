#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5+10;
struct order{
	int y,x;
}f[maxn];

int n,m,a[maxn] = {0};

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int g = a[1];
	int k = 1,tmp = 0;
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(k = 1;k <= n;k++){
				f[++tmp].x = k;
				f[tmp].y = i;
			}
		}else{
			for(k = m;k >= 1;k--){
				f[++tmp].x = k;
				f[tmp].y = i;
			}
		}
	}
	sort(a+1,a+n*m+1);
	int ans = 0;
	for(int i = n*m;i >= 1;i--){
		if(g == a[i]){
			ans = n*m-i+1;
			break;
		}
	}
	printf("%d %d\n",f[ans].y,f[ans].x);
	return 0;
}
