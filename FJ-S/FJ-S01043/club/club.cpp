#include<bits/stdc++.h>

using namespace std;

long long n;
long long a[100005][5];
long long cnt[5];
vector<long long> chazhi;

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int T;
	cin>> T;
	
	while(T--){
		
		cin>> n;
		
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin>> a[i][j];
			}
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				cnt[1] ++;
				ans += a[i][1];
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				cnt[2] ++;
				ans += a[i][2];
			}
			else{
				cnt[3] ++;
				ans += a[i][3];
			}
		}
		long long h = n / 2;
		if(cnt[1] > h){
//			cout<< "1 \n";
			for(int i = 1; i <= n; i++){
				if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
					chazhi.push_back(a[i][1] - max(a[i][2], a[i][3]));
				}
			}
			sort(chazhi.begin(), chazhi.end());
			for(int i = 0; i < cnt[1] - h; i++){
				ans -= chazhi[i];
			}
		}
		else if(cnt[2] > h){
//			cout<< "2 \n";
			for(int i = 1; i <= n; i++){
				if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
					chazhi.push_back(a[i][2] - max(a[i][1], a[i][3]));
				}
			}
			sort(chazhi.begin(), chazhi.end());
			for(int i = 0; i < cnt[2] - h; i++){
				ans -= chazhi[i];
			}
		}
		else if(cnt[3] > h){
//			cout<< "3 \n";
			for(int i = 1; i <= n; i++){
				if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1]){
					chazhi.push_back(a[i][3] - max(a[i][1], a[i][2]));
				}
			}
			sort(chazhi.begin(), chazhi.end());
			for(int i = 0; i < cnt[3] - h; i++){
				ans -= chazhi[i];
			}
		}
		
//		else{
//			cout<< "0 \n";
//		}
		
		memset(cnt, 0, sizeof(cnt));
		chazhi.clear();
		cout<< ans << "\n";
	}
	
	return 0;
} 
