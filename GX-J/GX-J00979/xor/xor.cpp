#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int uint;

uint arr[500005];

bool visted[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    uint n,k;
    cin >> n >> k;

    for(uint i = 0; i < n; i++){
        cin >> arr[i];
    }

    uint cnt = 0;
    
    uint next_start = 0;
    

    for(uint qujiansize = 0; qujiansize < n; qujiansize++){
        // cout << "New qujian size: " << qujiansize << endl;
        for(uint start = next_start; start < n - qujiansize; start++){
            uint end = start + qujiansize;
            uint Xor = 0;
            bool vst = false;
            int vst_right = 0;
            for(uint i = start; i <= end; i++){
                // if visited, gun
                if(visted[i]){
                    vst = true;
                    vst_right = i;
                    continue; //gun!
                }
                Xor ^= arr[i];
            }
            if(vst){// Gun!
                if(vst_right+1 - next_start <= next_start) {
                    next_start = vst_right+1;
                }
                continue;
            } 

            // cout << "Check: [" << start << ", " << end << "]" << endl;

            if(Xor==k){
                // cout << "Selected!" << endl;
                cnt++;
                memset(visted+start, qujiansize+1, true);

                if(start+1 - next_start <= next_start) {
                    next_start = start + 1;
                }
            }
            
        }
    }

    cout << cnt;

    return 0;
}