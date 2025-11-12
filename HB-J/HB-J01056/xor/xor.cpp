#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt = 0;
    cin >> n >> k;
    vector<int> a(n,0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int xor_num,x = 0;
    for(int i = 0;i < n;i++){
        xor_num = a[i];
        x = i;
        if(xor_num == k){
            cnt++;
            i = x;
            continue;
        }
        for(int j = i + 1;j < n;j++){
            xor_num ^= a[j];
            if(xor_num == k){
                cnt++;
                x = j;
                break;
            }
        }
        i = x;
    }
    cout << cnt;


	return 0;
}

