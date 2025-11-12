#include <iostream>
using namespace std;

int n, k;
bool used[500005];
int num[500005];
int prefix[500005];

void init(){
    prefix[0] = num[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] ^ num[i];
    }
}

int sum(int l, int r){
    if (l == 0){
        return prefix[r];
    }
    return prefix[r] ^ prefix[l-1];
}


int main(){


    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
// for (int i = 0; i < n; i++){cout << num[i];}
    init();

// for (int i = 0; i < n; i++){cout << prefix[i];}
    int ans = 0;
    for (int i=1; i<=n; i++){

        for (int st=0; st<=n-i; st++){

            if (sum(st, st+i-1) == k){

                bool used_any = 0;
                for (int j=st; j<=st+i-1; j++){
                    if (used[j]){
                        used_any = 1;
                        break;
                    }
                }
                if (used_any){
                    break;
                }
                ans++;
                for (int j=st; j<=st+i-1; j++){
                    used[j] = 1;
                }
                
            }


        }
    }

    cout << ans;
    cout << endl;
    return 0;

}