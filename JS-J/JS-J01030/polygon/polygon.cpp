#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[5005],b[5005],ans = 0;
int main(){
    ifstream fin("polygon.in");
    ofstream fout("polygon.out");
    fin >> n;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        fin >> a[i];
        if(a[i] != 1) flag = false;
    }
    if(flag){
        fout << 0;
        return 0;
    }
    for(int i = 3;i <= n;i++){
        b[1] = 1;
        for(int j = 2;j <= i;j++){
            b[j] = b[j-1]+1;
        }
        while(b[1] <= i){
            long long m = -1,sum = 0;
            for(int j = 1;j <= i;j++){
                sum += a[b[j]];
                m = max(m,a[b[j]]);
            }
            if(sum > m*2){
                ans++;
            }
            b[i] ++;
            long long tmp = i+1;
            for(int j = i;j > 1;j--){
                if(b[j] > n-(i-j)) {
                    b[j-1] ++;
                    tmp = j;
                }
            }
            for(int j = tmp;j <= i;j++){
                b[j] = b[j-1]+1;
            }
            if(b[i] > n) break;
        }
    }
    fout << ans % 998244353;
    return 0;
}
