#include <iostream>
#include <vector>
#define first l
#define second r

using namespace std;
const int maxn = 5e5+5;

int A[maxn];
vector<pair<int,int>> P;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k,ans=0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    //
    for(int left = 1; left <= n; left++){
        for(int right = left; right <= n; right++)
        {
            int x = A[left];
            for(int temp = left+1; temp <= right; temp++){
                x ^= A[temp];
            }
            if(x == k) {
                left = right;
                ans++;
                break;
            }
        }
    }
    //

    //
    cout << ans;

    return 0;
}
