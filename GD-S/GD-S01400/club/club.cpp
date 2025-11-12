#include<bits/stdc++.h>
using namespace std;

const int csp_N = 1e5 + 5;
int csp_a[csp_N][5];
pair<int,int> csp_t[csp_N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int csp_Q;
	cin >> csp_Q;
	while(csp_Q--){
		int csp_n,csp_k1 = 0,csp_k2 = 0,csp_k3 = 0;
		cin >> csp_n;
		long long csp_sum = 0;
		for(int i = 1;i <= csp_n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> csp_a[i][j];
			}
			if(csp_a[i][1] == csp_a[i][2] && csp_a[i][2] == csp_a[i][3]) csp_k1++,csp_k2++,csp_k3++;
			else if(csp_a[i][1] > csp_a[i][2] && csp_a[i][1] > csp_a[i][3]) csp_k1++;
			else if(csp_a[i][2] > csp_a[i][1] && csp_a[i][2] > csp_a[i][3]) csp_k2++;
			else if(csp_a[i][3] > csp_a[i][1] && csp_a[i][3] > csp_a[i][2]) csp_k3++;
			else if(csp_a[i][1] == csp_a[i][2]) csp_k1++,csp_k2++;
			else if(csp_a[i][1] == csp_a[i][3]) csp_k1++,csp_k3++;
			else if(csp_a[i][2] == csp_a[i][3]) csp_k2++,csp_k3++;
			
		}
		if(max(csp_k1,max(csp_k2,csp_k3)) <= csp_n / 2){
			for(int i = 1;i <= csp_n;i++){
				csp_sum += max(csp_a[i][1],max(csp_a[i][2],csp_a[i][3]));
			}
			cout << csp_sum << '\n';
			continue;
		}
		if(csp_k1 > csp_n / 2){
			int csp_bri = csp_k1 - csp_n / 2;
			int csp_len = 0;
			for(int i = 1;i <= csp_n;i++){
				if(csp_a[i][1] >= csp_a[i][2] && csp_a[i][1] >= csp_a[i][3]){
					csp_len++;
					csp_t[csp_len].second = i;
					csp_t[csp_len].first = csp_a[i][1] - (csp_a[i][2] > csp_a[i][3] ? csp_a[i][2] : csp_a[i][3]);
				}
			}
			sort(csp_t + 1,csp_t + csp_len + 1);
			for(int i = 1;i <= csp_bri;i++){
				int csp_p = csp_t[i].second;
				if(csp_a[csp_p][2] > csp_a[csp_p][3]){
					csp_sum += csp_a[csp_p][2];
				}else{
					csp_sum += csp_a[csp_p][3];
				}
			}
			for(int i = csp_bri + 1;i <= csp_k1;i++){
				csp_sum += csp_a[csp_t[i].second][1];
			}
			for(int i = 1;i <= csp_n;i++){
				if(csp_a[i][1] < csp_a[i][2] || csp_a[i][1] < csp_a[i][3]){
					csp_sum += max(csp_a[i][2],csp_a[i][3]);
				}
			}
		}else if(csp_k2 > csp_n / 2){
			int csp_bri = csp_k2 - csp_n / 2;
			int csp_len = 0;
			for(int i = 1;i <= csp_n;i++){
				if(csp_a[i][2] >= csp_a[i][1] && csp_a[i][2] >= csp_a[i][3]){
					csp_len++;
					csp_t[csp_len].second = i;
					csp_t[csp_len].first = csp_a[i][2] - (csp_a[i][1] > csp_a[i][3] ? csp_a[i][1] : csp_a[i][3]);
				}
			}
			sort(csp_t + 1,csp_t + csp_len + 1);
			for(int i = 1;i <= csp_bri;i++){
				int csp_p = csp_t[i].second;
				if(csp_a[csp_p][1] > csp_a[csp_p][3]){
					csp_sum += csp_a[csp_p][1];
				}else{
					csp_sum += csp_a[csp_p][3];
				}
			}
			for(int i = csp_bri + 1;i <= csp_k2;i++){
				csp_sum += csp_a[csp_t[i].second][2];
			}
			for(int i = 1;i <= csp_n;i++){
				if(csp_a[i][2] < csp_a[i][1] || csp_a[i][2] < csp_a[i][3]){
					csp_sum += max(csp_a[i][1],csp_a[i][3]);
				}
			}
		}else if(csp_k3 > csp_n / 2){
			int csp_bri = csp_k3 - csp_n / 2;
			int csp_len = 0;
			for(int i = 1;i <= csp_n;i++){
				if(csp_a[i][3] >= csp_a[i][1] && csp_a[i][3] >= csp_a[i][2]){
					csp_len++;
					csp_t[csp_len].second = i;
					csp_t[csp_len].first = csp_a[i][3] - (csp_a[i][1] > csp_a[i][2] ? csp_a[i][1] : csp_a[i][2]);
				}
			}
			sort(csp_t + 1,csp_t + csp_len + 1);
			for(int i = 1;i <= csp_bri;i++){
				int csp_p = csp_t[i].second;
				if(csp_a[csp_p][1] > csp_a[csp_p][2]){
					csp_sum += csp_a[csp_p][1];
				}else{
					csp_sum += csp_a[csp_p][2];
				}
			}
			for(int i = csp_bri + 1;i <= csp_k3;i++){
				csp_sum += csp_a[csp_t[i].second][3];
			}
			for(int i = 1;i <= csp_n;i++){
				if(csp_a[i][3] < csp_a[i][1] || csp_a[i][3] < csp_a[i][2]){
					csp_sum += max(csp_a[i][1],csp_a[i][2]);
				}
			}
		}
		cout << csp_sum << '\n';
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
