#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1,a + 1 + n);
		sort(b + 1,b + 1 + n);
		sort(c + 1,c + 1 + n);
		int cnt = 0;
		int num = 0;
		int sum = 0;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(cnt < n / 2){
				ans += a[i];
				cnt++;
			}else if(num < n / 2){
				ans += b[i];
				num++;
			}else if(sum < n / 2){
				ans += c[i];
				sum++;
			}
		}
		cout << ans;
		if(i != t){
			cout << endl;
		}		
	}
	
	return 0;
}
