#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 5;

int T,n;
int a[N][3];
int cnt[3],sum;

priority_queue<int, vector<int>, greater<int> > q[3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    cin >> T;
    while(T--){
        cin >> n;
        sum = 0;
        cnt[0] = cnt[1] = cnt[2] = 0;
        while(q[0].size()) q[0].pop();
        while(q[1].size()) q[1].pop();
        while(q[2].size()) q[2].pop();
        for(int i = 1;i <= n;i++){
            int mx = 0;
            a[i][0] = -1;
            for(int j = 0;j < 3;j++){
                cin >> a[i][j];
                if(a[i][j] > a[i][mx]){
                    mx = j;
                }
            }
            int sec = -1;
            for(int j = 0;j < 3;j++){
                if(j == mx) continue;
                sec = max(sec,a[i][j]);
            }
            if(q[mx].size() == n / 2){
                if(a[i][mx] - sec > q[mx].top()){
                    sum += a[i][mx];
                    sum -= q[mx].top();
                    q[mx].pop();
                    q[mx].push(a[i][mx] - sec);
                }else{
                    sum += sec;
                }
            }else{
                q[mx].push(a[i][mx] - sec);
                sum += a[i][mx];
            }
        }

        cout << sum << endl;
    }
}