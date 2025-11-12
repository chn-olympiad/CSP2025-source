#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
int n , k , ans;
int a[N];
char visited[N];
int main(){
    freopen("xor.in", "r" , stdin);
    freopen("xor.out", "w" , stdout);
    cin >> n >> k;
    memset(visited , '0' , sizeof(visited));
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    if(k == 0){
        for(int i = 1; i <= n; ++i){
            if(a[i] == 0){
                ++ans;
                visited[i] = '1';
            }
            if(a[i] == a[i + 1] && visited[i] == '0' && visited[i + 1] == '0'){
                ++ans;
                visited[i] == '1';
                visited[i + 1] == '1';
            }
        }
    }
    if(k == 1){
        for(int i = 1; i <= n; ++i){
            if(a[i] == 1 && visited[i] == '0'){
                a[i] = 0;
                ++ans;
                visited[i] == '1';
            }
            if(a[i] != a[i + 1] && visited[i] == '0' && visited[i + 1] == '0'){
                ++ans;
                visited[i] = '1';
                visited[i + 1] = '1';
            }
        }
    }
    cout << ans << endl;
    return 0;
}
