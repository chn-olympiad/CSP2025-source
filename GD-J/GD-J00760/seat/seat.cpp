#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],x,c,r,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> x;
	a[1] = x;
	for(int i = 2;i <= n*m;i++){
		scanf("%d",a+i);
	}
	for(int i = 2;i <= n*m;i++)if(a[i] > x)ans++;
//	sort(a+1,a+n*m);
//	for(int i = 1;i <= n*m;i++){
//		if(a[i] == x){
//			ans = i;
//			break;
//		}
//	}
//	ans = n*m - ans;
	if(ans % n == 0){
		if((ans/n)&1)cout << ans/n << ' ' << n;
		else cout << ans / n << ' ' << 1;
	}
	else{
		if((ans/n)&1)cout << (ans/n)+1 << ' ' << m-(ans%n)+1;
		else cout << (ans/n)+1 << ' ' << ans % n;
	}
	return 0;
}
