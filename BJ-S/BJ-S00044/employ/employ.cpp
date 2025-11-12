#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
bool vis[505];
int ans;
void DFS(int i,int num,int AA){
	//cout << i << ' ' << num << ' ' << AA << endl;
	if(i > n){
		//cout << num << endl;
		if(num >= m){
			ans++;
			if(ans >= 998244353){
				ans -= 998244353;
				//cout << 1;
			}
			//cout << ans << endl;
		}
		return;
	}
	for(int j = 1;j <= n;j++){
		if(!vis[j]){
			vis[j] = 1;
			DFS(i+1,num+(s[i-1] == '1' && AA < a[j]),AA+(s[i-1] == '0'));
			vis[j] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		
	}
	DFS(1,0,0);
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2
*/