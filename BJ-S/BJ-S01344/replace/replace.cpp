#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string zuz[N],zuy[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> zuz[i] >> zuy[i];
	}
	while(q--){
		string a,b;
		cin >> a >> b;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(a.find(zuz[i]) && b.find(zuy[i])){
				ans++;
			}
		}
		cout << ans;
	}
	
	return 0;
}
