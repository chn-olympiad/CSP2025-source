#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,k;
int a[N];
int b[N];
int zt[2000005];
queue <int> q;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	cin >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	q.push(0);
	zt[0] ++;
	for(int i = 1;i <= n;i ++){
		q.push(b[i]);
		if(zt[b[i] ^ k]){
			ans ++;
			while(!q.empty()){
				int d = q.front();
				q.pop();
				zt[d] --;
			}
		}
	}
	cout << ans;
	return 0;
}
