#include <bits/stdc++.h>
using namespace std;

bool vis[5010];
int wood[5010];



void mymain(){
	int n;
	cin >> n;
	if(n == 3){
		int len = 0, m_len = -1;
		for(int i = 1; i <= n; i++){
			cin >> wood[i];
			len += wood[i];
			m_len = max(m_len, wood[i]);
		}
		cout << (len > 2 * m_len ? 1 : 0);
		return;
	}else{
		int m = n - 2;
		int ans = m * (m - 1);
		cout << ans << endl;
		return;
	}
	cout << 998244352;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	int n;
//	cin >> n;
//	while(n--){
		mymain();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//#Shang4Shan3Ruo6Shui4












