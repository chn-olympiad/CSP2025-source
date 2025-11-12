#include<bits/stdc++.h>
using namespace std;
int test;
inline void solve(){
	int n;
	pair<int,pair<int,int>> a[100001];
	cin >> n;
	bool A = true,B = true,C = true;
	for(int i = 1;i <= n; i++){
		cin >> a[i].first>> a[i].second.first >> a[i].second.second;
		if(a[i].second.first != 0 || a[i].second.second!= 0){
			A = false;
		}
		if(a[i].second.second!= 0){
			B = false;
		}
		if(a[i].first != 0 || a[i].second.first != 0 || a[i].second.second != 0 || a[i].first != 20000 || a[i].second.first != 20000 || a[i].second.second != 20000){
			C = false;
		}	
	}
	if(n == 2){
		int b[1001];
		b[1] = a[1].first + a[2].second.first;
		b[2] = a[1].first + a[2].second.second;
		b[3] = a[1].second.first + a[2].first;
		b[4] = a[1].second.first + a[2].second.second;
		b[5] = a[1].second.second+ a[2].first;
		b[6] = a[1].second.second + a[2].second.first;
		sort(b + 1,b + 7);
		cout << b[6] << endl;
		return;
	}else{
		if(A){
			sort(a + 1,a + n + 1);
			long long ans = 0;
			for(int i = n / 2 + 1;i <= n;i++){
				ans += a[i].first;
			}
			cout << ans << endl;
			return;
		}
		/*if(B){
			sort(a + 1,a + n + 1);
			int a = 0,b = 0,c = 0;
			for(int i = 1;i <= n;i++){	
				int x = a[i].first;
				int y = a[i].second.first;
				if(x > y){ 
					a++;
				}else{
					if(y > x){
						b++;
					}else{
						c++;
					}
				}
			}
			if(c){
				if(a <= n / 2 && b <= n / 2){
					long long ans = 0;
					for(int i = 1;i <= n;i++){
						int x = a[i].first;
						int y = a[i].second.first;
						ans += max(x,y);
					}
					cout << ans;
				}else{
					pair<int,int> chazhi[100001];
					memset(chazhi,INT_MAX,sizeof(chazhi));
					if(a > b){
						a += c;
						long long ans = 0;
						for(int i = 1;i <= n;i++){
							int x = a[i].first;
							int y = a[i].second.first;
							ans += max(x,y);
						}
						for(int i = 1;i <= n;i++){
							int x = a[i].first;
							int y = a[i].second.first;
							if(x >= a[i].y){
								chazhi[i].first = x - y;
								chazhi[i].second = i;
							}
						}
						sort(chazhi + 1,chazhi + n + 1);
						for(int i = 1;i <= a - b;i++){
							ans -= chazhi[i].first;
						}
						cout << ans;
					}else{
						if(b > a){
							a += c;
						}
					}
				}
			}
		}*/
		if(C){
			int numof20000 = 0;
			long long ans = 0;
			for(int i = 1;i <= n; i++){
				if((a[i].first == 20000 || a[i].second.first == 20000 || a[i].second.second == 20000) && numof20000 < n / 2){
					ans += 20000;
					numof20000++;
				}else{
					ans += 0;
				}
			}
			cout << ans << endl;
			return;
		}
		if(n == 4){
			int b[101];
			b[1] = a[1].first + a[2].first + a[3].second.first + a[4].second.first;
			b[2] = a[1].first + a[2].first + a[3].second.second + a[4].second.first;
			b[3] = a[1].first + a[2].first + a[3].second.first + a[4].second.second;
			b[4] = a[1].first + a[2].first + a[3].second.second + a[4].second.second;
			b[5] = a[1].first + a[2].second.first + a[3].first + a[4].second.first;
			b[6] = a[1].first + a[2].second.first + a[3].first + a[4].second.second;
			b[7] = a[1].first + a[2].second.first + a[3].second.first + a[4].first;
			b[8] = a[1].first + a[2].second.first + a[3].second.first + a[4].second.second;
			b[9] = a[1].first + a[2].second.first + a[3].second.second + a[4].first;
			b[10] = a[1].first + a[2].second.first + a[3].second.second + a[4].second.first;
			b[11] = a[1].first + a[2].second.first + a[3].second.second + a[4].second.second;
			b[12] = a[1].first + a[2].second.second + a[3].first + a[4].second.first;
			b[13] = a[1].first + a[2].second.second + a[3].first + a[4].second.second;
			b[14] = a[1].first + a[2].second.second + a[3].second.first + a[4].first;
			b[15] = a[1].first + a[2].second.second + a[3].second.first + a[4].second.first;
			b[16] = a[1].first + a[2].second.second + a[3].second.first + a[4].second.second;
			b[17] = a[1].first + a[2].second.second + a[3].second.second + a[4].first;
			b[18] = a[1].first + a[2].second.second + a[3].second.second + a[4].second.first;
			b[19] = a[1].second.second + a[2].second.second + a[3].second.first + a[4].second.first;
			b[20] = a[1].second.first + a[2].first + a[3].first + a[4].second.first;
			b[21] = a[1].second.first + a[2].first + a[3].first + a[4].second.second;
			b[22] = a[1].second.first + a[2].first + a[3].second.first + a[4].first;
			b[23] = a[1].second.first + a[2].first + a[3].second.first + a[4].second.second;
			b[24] = a[1].second.first + a[2].first + a[3].second.second + a[4].first;
			b[25] = a[1].second.first + a[2].first + a[3].second.second + a[4].second.first;
			b[26] = a[1].second.first + a[2].first + a[3].second.second + a[4].second.second;
			b[27] = a[1].second.first + a[2].second.first + a[3].first + a[4].first;
			b[28] = a[1].second.first + a[2].second.first + a[3].first + a[4].second.second;
			b[29] = a[1].second.first + a[2].second.second + a[3].second.second + a[4].first;
			b[30] = a[1].second.first + a[2].second.first + a[3].second.second + a[4].second.second;
			b[31] = a[1].second.first + a[2].second.second + a[3].first + a[4].first;
			b[32] = a[1].second.first + a[2].second.second + a[3].first + a[4].second.first;
			b[33] = a[1].second.first + a[2].second.second + a[3].first + a[4].second.second;
			b[34] = a[1].second.first + a[2].second.second + a[3].second.first + a[4].first;
			b[35] = a[1].second.first + a[2].second.second + a[3].second.first + a[4].second.second;
			b[36] = a[1].second.first + a[2].second.second + a[3].second.second + a[4].first;
			b[37] = a[1].second.first + a[2].second.second + a[3].second.second + a[4].second.first;
			b[38] = a[1].second.second + a[2].first + a[3].first + a[4].second.first;
			b[39] = a[1].second.second + a[2].first + a[3].first + a[4].second.second;
			b[40] = a[1].second.second + a[2].second.second + a[3].second.first + a[4].first;
			b[41] = a[1].second.second + a[2].first + a[3].second.first + a[4].first;
			b[42] = a[1].second.second + a[2].first + a[3].second.first + a[4].second.first;
			b[43] = a[1].second.second + a[2].first + a[3].second.first + a[4].second.second;
			b[44] = a[1].second.second + a[2].first + a[3].second.second + a[4].first;
			b[45] = a[1].second.second + a[2].first + a[3].second.second + a[4].second.first;
			b[46] = a[1].second.second + a[2].second.first + a[3].first + a[4].first;
			b[47] = a[1].second.second + a[2].second.first + a[3].first + a[4].second.first;
			b[48] = a[1].second.second + a[2].second.first + a[3].first + a[4].second.second;
			b[49] = a[1].second.second + a[2].second.first + a[3].second.first + a[4].first;
			b[50] = a[1].second.second + a[2].second.first + a[3].second.first + a[4].second.second;
			b[51] = a[1].second.second + a[2].second.first + a[3].second.second + a[4].first;
			b[52] = a[1].second.second + a[2].second.first + a[3].second.second + a[4].second.first;
			b[53] = a[1].second.second + a[2].second.second + a[3].first + a[4].first;
			b[54] = a[1].second.second + a[2].second.second + a[3].first + a[4].second.first;
			sort(b + 1,b + 55);
			cout << b[54] << endl;
			return;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
