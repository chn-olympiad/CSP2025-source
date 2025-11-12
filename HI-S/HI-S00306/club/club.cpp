#include<bits/stdc++.h>
using namespace std;
int t;
long long n,ans,a1[100005],a2[100005],a3[100005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int k = 1;k <= t;k++){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		sort(a1+1,a1+n+1,cmp);
		sort(a2+1,a2+n+1,cmp);
		sort(a3+1,a3+n+1,cmp);
		for(int i = 1;i <= n / 2;i++){
			ans += a1[i];
		}
		cout << ans;
	}
	return 0;
}

