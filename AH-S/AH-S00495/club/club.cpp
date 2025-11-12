#include<bits/stdc++.h>
using namespace std;
int n;//fxi = axi + sum;
int a[100005][3];
int f[100005][3][4];
int xl, yl, zl;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        for(int i = 1; i <= n; i++){
            bool flag = 1;
            for(int j = 1; j <= n-i; j++){
                if(a[j][0] == a[j+1][0]){
                    if(a[j][1] == a[j+1][1])
                        if(a[j][2] > a[j+1][2]){
                            swap(a[j], a[j+1]);
                            flag = 0;
                        }
                    else if(a[j][1] > a[j+1][1]){
                        swap(a[j],a[j+1]);
                        flag = 0;
                    }
                }
                else if(a[j][0] > a[j+1][0]){
                    swap(a[j],a[j+1]);
                    flag = 0;
                }
            }
            if(flag) break;
        }
        //int check = n;
        //do{
            for(int i = 1; i <= n; i++){
                for(int j = 0; j < 3; j++){
                    for(int k = 1; k <= 3; k++)
                        f[i][j][k] = 0;
                }
                int sum, cnt;
                if(f[i-1][0][0] > f[i-1][1][0] && f[i-1][0][0] > f[i-1][2][0]){
                    cnt = 0;
                }
                else if(f[i-1][1][0] > f[i-1][0][0] && f[i-1][1][0] > f[i-1][2][0]){
                    cnt = 1;
                }
                else{
                    cnt = 2;
                }
                sum = f[i-1][cnt][0];
                xl = f[i-1][cnt][1], yl = f[i-1][cnt][2], zl = f[i-1][cnt][3];
                f[i][0][0] = f[i][1][0] = f[i][2][0] = sum;
                if(xl*2 < n){
                    f[i][0][0] += a[i][0];
                    f[i][0][1]++;
                }
                else{
                    if(a[i][0] >= sum){
                        f[i][0][0] = a[i][0];
                        f[i][0][1] = -xl+1;
                    }
                }
                if(yl*2 < n){
                    f[i][1][0] += a[i][1];
                    f[i][1][2]++;
                }
                else{
                    if(a[i][1] >= sum){
                        f[i][1][0] = a[i][1];
                        f[i][1][2] = -yl+1;
                    }
                }
                if(zl*2 < n){
                    f[i][2][0] += a[i][2];
                    f[i][2][3]++;
                }
                else{
                    if(a[i][2] >= sum){
                        f[i][2][0] = a[i][2];
                        f[i][2][3] = -zl+1;
                    }
                }
                //f[i][0][0] = max(f[i][0][0], a[i][0]);
                //f[i][1][0] = max(f[i][1][0], a[i][1]);
                //f[i][2][0] = max(f[i][2][0], a[i][2]);
                for(int j = 0; j < 3; j++){
                    f[i][j][1] += xl;
                    f[i][j][2] += yl;
                    f[i][j][3] += zl;
                }
            }//dp
        //}while(check == n)
        int maxn = max({f[n][0][0], f[n][1][0], f[n][2][0]});
        cout << maxn << endl;
	}
	return 0;
}
