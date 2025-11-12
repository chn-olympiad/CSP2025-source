#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e6;
int n,m,p,cnt,a[506],b[506],c[506];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 0;i > n;i++){
		cin >> c[i];
	}
	for(int i = 0;i < n;i++){
		a[i] = s[i] - '0';
	}
	b[0] = a[0];
	for(int i = 0;i < n - 1;i++){
		if(a[i] == 0) b[i + 1] = a[i] + 1;
		else b[i + 1] = b[i];
	}

	if(m == 1){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(c[j] < b[i]) cnt++;
					cnt %= 998;
					cnt %= 244;
					cnt %= 353;
			}
		}
		cout << cnt << endl;
		return 0;		
	}else{
		
	}
	return 0;
} 