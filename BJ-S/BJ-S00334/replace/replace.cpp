#include <iostream>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    string z[n + 1][3];
    for(int i = 1;i <= n;i++){
        cin >> z[i][1] >> z[i][2];
    }
    string olds,news;
    for(int i = 1;i <= q;i++){
        cin >> olds >> news;
        int ans = 0;
        //cout << olds << " " << news << endl << endl;
        for(int j = 1;j <= n;j++){
            string ts = "",te = "";
            if(olds.find(z[j][1]) != string::npos){
                //cout << olds.find(z[j][1]) << endl;
                //cout << z[j][1] << " " << z[j][2] << endl;
                int ps = olds.find(z[j][1]);
                for(int o = 0;o < ps;o++){
                    ts += olds[o];
                }
                for(int o = ps + (int)z[j][1].length();o < (int)olds.length();o++){
                    te += olds[o];
                }
                if(ts + z[j][2] + te == news){
                    ans++;
                }
                //cout << ts + z[j][2] + te << "\n\n";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
