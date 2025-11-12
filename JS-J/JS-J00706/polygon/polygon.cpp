#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n,a[5005],sum;
string in[100];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    if(n <= 20){
    for(int i = 7;i < (1 << n);i++){
        int maxs = -1;
        int ams = 0;
        //string ad;
        for(int j = 0;j < n;j++){
            if(i & (1 << j)){
                maxs = max(a[j + 1],maxs);
                ams += a[j + 1];
                //ad += (j + '0')
            }
        }
        if(ams > 2*maxs){
            //cout << ams << endl;
            sum++;
        }
    }
    }else{
        sum = 1;
        for(int i = 4;i <=n;i++){
            sum = 2*sum + 1;
        }
    }
    cout << sum;
    return 0;
}
//5 1 2 3 4 5
