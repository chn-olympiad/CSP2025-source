#include<bits/stdc++.h>
using namespace std;

string s;
int c[505];
int ans=1,cnt=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n , m;
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)
	cin >> c[i];
	for(int i = 1 ; i <= n ; i++){
		ans *= i;
	}
	for(int i = 1 ; i <= n - m ; i++){
		cnt *= i;
	}
	cout << ans / cnt;
}
