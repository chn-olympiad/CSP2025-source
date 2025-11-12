//GZ-S00279 林映辰 贵阳市第十八中学 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+20;
int t = 0;
int aa[N],bb[N],cc[N];
int ans;
void fun(int k,int a,int b,int c,int an,int top){
	int a1 = aa[k],b1 = bb[k],c1 = cc[k];
	if(k <= 2*top){
		if(a < top){
			fun(k+1,a+1,b,c,an+a1,top);
		}
		if(b < top){
			fun(k+1,a,b+1,c,an+b1,top);
		}
		if(c < top){
			fun(k+1,a,b,c+a,an+c1,top);
		}
	}
	else{
		if(an > ans){
			ans = an;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >> aa[i] >> bb[i] >> cc[i];
		}
		ans = 0;
		fun(0,0,0,0,0,n/2);
		cout << ans << '\n';
		for(int i = 0;i < n;i++){
			aa[i] = 0;
			bb[i] = 0;
			cc[i] = 0;
		}
	}
	return 0;
}

