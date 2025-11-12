#include<bits/stdc++.h>//develop ways
using namespace std;
const int maxn = 105 * 105;
int g[maxn];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n , m;
    cin >> n >> m;
    int R;
    for(int i = 1;i <= n * m;i++){
        cin >> g[i];
    }
    R = g[1];
    sort(g + 1,g + n * m + 1,cmp);

    int ansx,ansy;
    for(int i = 1;i <= n * m;i++){
        if(g[i] == R && i % n != 0){
            ansx = (i / n) + 1;//find the x

                if(ansx % 2 == 1){//from the first to the end
                ansy = i % n;
                }
                else if(ansx % 2 == 0){//from the end to the first
                    ansy = (n + 1) - (i % n);
                }
                break;
        }
        else if(g[i] == R && i % n == 0){
             ansx = (i / n);//find the x

                if(ansx % 2 == 1){//from the first to the end
                    ansy = n;
                }
                else if(ansx % 2 == 0){//from the end to the first
                    ansy = 1;
                }
                break;
        }
    }
    cout << ansx << ' ' << ansy;
    return 0;
}
