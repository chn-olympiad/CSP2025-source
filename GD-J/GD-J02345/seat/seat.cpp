#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)cin >> a[i];
	int score = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int pos; 
	for(int i = 1;i <= n*m;i++){
		if(a[i] == score){pos = i;break;}
	}
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				cnt++;
				if(cnt == pos){
					cout << i << " " << j;return 0;
				}
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				cnt++;
				if(cnt == pos){
					cout << i << " " << j;return 0; 
				}
			}
		}
	}
	return 0;
} 
