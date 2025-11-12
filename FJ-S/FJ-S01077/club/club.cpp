#include<bits/stdc++.h>
using namespace std;

int t,n;
int s[15000+10][15000+10];
int main() {
	
	freopen("nn.in","r",stdin);
	freopen("nn.out","w",stdout);
	
	cin >> t;
	
	for(int cc = 1; cc <= t; cc ++) {
		int ans = 0;
		int club_max = 0;
		
		cin >> n;
		club_max = n/2;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= 3; j ++) {
				cin >> s[i][j];
			}
			int maxx = -1;
			for(int j = 1; j <= 3; j ++) {
				if(maxx < s[i][j])
					s[i][4] = j;
				int sb = s[i][j];
				maxx = max(maxx, sb);
			}
		}
		
		int bumen_max[3+10] = {0};
		
		for(int i = 1; i <= n; i ++) {
			if(s[i][4] == 1) bumen_max[1] ++;
			if(s[i][4] == 2) bumen_max[2] ++;
			if(s[i][4] == 3) bumen_max[3] ++;
		}
		
		int bu_max = max(bumen_max[1], bumen_max[2]);
		bu_max = max(bu_max, bumen_max[3]);
		for(int i = 1; i <= 3; i ++) {
			int bumen_maxi = bumen_max[i];
			if(bu_max == bumen_maxi) {
				bu_max = i;
				break;
			}	
		}
		
		int bu_min = min(bumen_max[1], bumen_max[2]);
		bu_min = min(bu_min, bumen_max[3]);
		for(int i = 1; i <= 3; i ++) {
			int bumen_maxi = bumen_max[i];
			if(bu_min == bumen_maxi) {
				bu_min = i;
				break;
			}	
		}
		
		int bu_mee = 0;
		for(int i = 1; i <= 3; i ++) {
			if(i != bu_max && i != bu_min) {
				bu_mee = i;
			}
		}
		
		/**/
		int maxxx = 0;
		int club_num = 0;
		int jl_i=0;
		
		//////////////////////////
		for(int xx = 1; xx <= n; xx ++) {
			for(int i = 1; i <= n; i ++) {
			int nm = s[i][bu_max];
			int nm1 = s[i][4];
			int nm2 = bu_max;
			if(nm1 == nm2) {
				maxxx = max(maxxx, nm);
				jl_i = i; 
			}
			if(i == n) {
	//			for(int j = 1; j <= 13; j ++) {
	//				s[jl_i][j] = 0;
	//			}
				s[jl_i][1] = 0;s[jl_i][2] = 0;s[jl_i][3] = 0;
				
				if(club_num < club_max) {
	//				cout << "s[" << jl_i << "]" << "[4] = " << maxxx << " " << club_num << " ";
					ans += maxxx;
					maxxx = 0;
					club_num ++;
	//				cout << "ans = " << ans << " " << club_num << endl;
					} else {
						break;
					}
				}
			}
		}
		
		/////////////////////////////////
		maxxx = 0;
		club_num = 0;
		jl_i=0;
		for(int xx = 1; xx <= n; xx ++) {
			for(int i = 1; i <= n; i ++) {
			int nm = s[i][bu_mee];
			int nm1 = s[i][4];
			int nm2 = bu_mee;
			if(nm1 == nm2) {
				maxxx = max(maxxx, nm);
				jl_i = i; 
			}
			if(i == n) {
	//			for(int j = 1; j <= 13; j ++) {
	//				s[jl_i][j] = 0;
	//			}
				s[jl_i][1] = 0;s[jl_i][2] = 0;s[jl_i][3] = 0;
				
				if(club_num < club_max) {
	//				cout << "s[" << jl_i << "]" << "[4] = " << maxxx << " " << club_num << " ";
					ans += maxxx;
					maxxx = 0;
					club_num ++;
	//				cout << "ans = " << ans << " " << club_num << endl;
					} else {
						break;
					}
				}
			}
		}
		
		//////////////////////////////
		
		maxxx = 0;
		club_num = 0;
		jl_i=0;
		for(int xx = 1; xx <= n; xx ++) {
			for(int i = 1; i <= n; i ++) {
			int nm = s[i][bu_min];
			int nm1 = s[i][4];
			int nm2 = bu_min;
			if(nm1 == nm2) {
				maxxx = max(maxxx, nm);
				jl_i = i; 
			}
			if(i == n) {
	//			for(int j = 1; j <= 13; j ++) {
	//				s[jl_i][j] = 0;
	//			}
				s[jl_i][1] = 0;s[jl_i][2] = 0;s[jl_i][3] = 0;
				
				if(club_num < club_max) {
	//				cout << "s[" << jl_i << "]" << "[4] = " << maxxx << " " << club_num << " ";
					ans += maxxx;
					maxxx = 0;
					club_num ++;
	//				cout << "ans = " << ans << " " << club_num << endl;
					} else {
						break;
					}
				}
			}
		}
		
		
		///////////////////////////
		
		cout << ans << endl;
	}
	
	return 0;
}
