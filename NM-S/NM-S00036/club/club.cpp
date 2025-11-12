#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n ,m;
int x , y , z;
int x1[N];
int d1[N];
int z1[N];



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> n ;
	int ans;
	for(int i = 1; i <= n;i++){
        ans = 0;
        cin >> m;
        int max_num = m / 2;
        for(int j = 1;j <= m;j++){
            cin >> x >> y >> z;
            int cnt = 0;
            if(m == 100000 ){
                if(x == 0 && y == 0){
                    cnt++;
                    z1[cnt] = z;
                }
                int cnt1 = 0;
                if(x == 0 && z == 0){
                    cnt1++;
                    d1[cnt1] = y;
                }
                int cnt2 = 0;
                if(z == 0 && y == 0){
                    cnt2++;
                    z1[cnt] = z;
                }
                if(cnt == m){
                    sort(x1 + 1,x1 + m + 1,greater<int>());
                    for(int i = 1;i <= m / 2;i++){
                        ans += x1[i];
                    }
                }else if(cnt1 == m){
                    sort(d1 + 1,d1 + m + 1,greater<int>());
                    for(int i = 1;i <= m / 2;i++){
                        ans += d1[i];
                    }
                }else if(cnt2 == m){
                    sort(z1 + 1,z1 + m + 1,greater<int>());
                    for(int i = 1;i <= m / 2;i++){
                        ans += z1[i];
                    }
                }
            cout << ans;
                break;
            }
            else{
                if(max(max(x , y) , max(y , z)) == x){
                ans += x;
            }else if(max(max(x , y) , max(y , z)) == y){
                ans += y;
            }else if(max(max(x , y) , max(y , z)) == z){
                ans += z;
            }
        }

	}

	cout << ans;

	return 0;
    }
}
