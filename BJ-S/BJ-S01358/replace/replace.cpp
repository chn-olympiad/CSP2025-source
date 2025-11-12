#include <iostream>
using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    int prev[200005] = { }, aft[200005] = { },
        c_prev[200005] = { }, c_aft[200005] = { };
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        string a,b;
        cin >> a >> b;
        for(int j = 0; j < a.length(); j++){
            //cout << j << " ";
            if(a[j] == 'b'){
                prev[i] = j;
                aft[i] = a.length() - j - 1;
                break;
            }
        }
        for(int j = 0; j < b.length(); j++){
            if(b[j] == 'b'){
                c_prev[i] = j;
                c_aft[i] = b.length() - j - 1;
                break;
            }
        }
        //cout << prevb[i] << " " << aftb[i] << " = " << c_prevb[i] << " " << c_aftb[i];
    }

    for(int i = 1; i <= q; i++){
        int ans = 0;
        string a,b;
        int aprev = 0,aaft = 0,bprev = 0,baft = 0;
        cin >>a >>b;

        for(int j = 0; j < a.length(); j++){
            //cout << j << " ";
            if(a[j] == 'b'){
                aprev = j;
                aaft = a.length() - j - 1;
                break;
            }
        }
        for(int j = 0; j < b.length(); j++){
            if(b[j] == 'b'){
                bprev = j;
                baft = b.length() - j - 1;
                break;
            }
        }

        for(int i = 1; i <= n; i++){
            if(aprev - prev[i] + c_prev[i] == bprev && aaft - aft[i] + c_aft[i] == baft){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
