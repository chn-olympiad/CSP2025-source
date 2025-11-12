#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N = 1e5+5;
int a1[N],a2[N],a3[N];
int b[N];
int sum;
int one,two,thr;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		int p = n/2;
		sum = 0;
		for(int i = 1;i <= n;i++){
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		sort(a1+1,a1+n+1);
		for(int i = n;i > p;i--){
			sum += a1[i];
		}
		cout << sum << endl;
	}
	return 0;
}