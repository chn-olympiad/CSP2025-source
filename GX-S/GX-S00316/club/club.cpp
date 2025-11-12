#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005], b[100005], c[100005];
int h[1145];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for(int e = 0; e < t; e++){
		cin >> n;
		int m = n/2;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		int maxn = -1
		if(n==2){
			int h[1] = a[1] + b[2];
			int h[2] = a[1] + c[2];
			int h[3] = b[1] + a[2];
			int h[4] = b[1] + c[2];
			int h[5] = c[1] + a[2];
			int h[6] = c[1] + b[2];
			for(int i = 1; i <= 6; i++){
				if(h[i] > maxn) maxn = h[i];
			}
			cout << maxn << endl;
		}else if(n == 4){
			int h[1] = a[1] + a[2];
			int h[2] = a[1] + a[3];
			int h[3] = a[1] + a[4];
			int h[4] = a[1] + b[2]
			int h[5] = a[1] + b[3];
			int h[6] = a[1] + b[4];
			int h[7] = a[1] + c[2]
			int h[8] = a[1] + c[3];
			int h[9] = a[1] + c[4];
			int h[10] = a[2] + a[3];
			int h[11] = a[2] + a[4];
			int h[12] = a[2] + b[1]
			int h[13] = a[2] + b[3];
			int h[14] = a[2] + b[4];
			int h[15] = a[2] + c[1]
			int h[16] = a[2] + c[3];
			int h[17] = a[2] + c[4];
			int h[18] = a[3] + a[4];
			int h[19] = a[3] + b[1]
			int h[20] = a[3] + b[2];
			int h[21] = a[3] + b[4];
			int h[22] = a[3] + c[1]
			int h[23] = a[3] + c[2];
			int h[24] = a[3] + c[4];
			int h[25] = a[4] + b[1]
			int h[26] = a[4] + b[2];
			int h[27] = a[4] + b[3];
			int h[28] = a[4] + c[1]
			int h[29] = a[4] + c[2];
			int h[30] = a[4] + c[3];
			
			int h[31] = b[1] + b[2];
			int h[32] = b[1] + b[3];
			int h[33] = b[1] + b[4];
			int h[34] = b[1] + c[2];
			int h[35] = b[1] + c[3];
			int h[36] = b[1] + c[4];
			int h[37] = b[2] + b[3];
			int h[38] = b[2] + b[4];
			int h[39] = b[2] + c[1];
			int h[40] = b[2] + c[3];
			int h[41] = b[2] + c[4];
			int h[42] = b[3] + b[4];
			int h[43] = b[3] + c[1];
			int h[44] = b[3] + c[2];
			int h[45] = b[3] + c[4];
			int h[46] = b[4] + c[1];
			int h[47] = b[4] + c[2];
			int h[48] = b[4] + c[3];
			
			int h[49] = c[1] + b[2];
			int h[50] = c[1] + b[3];
			int h[51] = c[1] + c[4];
			int h[52] = c[2] + c[3];
			int h[53] = c[2] + c[4];
			int h[54] = c[4] + c[3];
			for(int i = 1; i <= 54; i++){
				if(h[i] > maxn) maxn = h[i];
			}
			cout << maxn << endl;
		}else{
			cout << 1000000;
		}
	}
	return 0;
}
// da biao chu sheng yi !!!
