/********************
 * @GavinCQTD
 * 2025/11/1 CSP-S
 * C. replace
 * 1000 ms / 2048 MB
********************/

#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

namespace Gavin{
    constexpr int BASE1=17,BASE2=37;
    
    int n,q,l1[200005],pref[200005];
    string s[200005][3];
    ull pwr1[5000005],pwr2[5000005],hsh1[5000005][5],hsh2[5000005][5];

    pair<ull,ull> getHash(int id,int l,int r){
        return make_pair((hsh1[r][id]-hsh1[l-1][id])/pwr1[l],(hsh2[r][id]-hsh2[l-1][id])/pwr2[l]);
    }

    int main(){
        cin >> n >> q;
        
        pwr1[0] = pwr2[0] = 1;
        for(int i=1;i<=5000000;i++){
            pwr1[i] = pwr1[i-1]*BASE1;
            pwr2[i] = pwr2[i-1]*BASE2;
        }
        
        for(int i=1;i<=n;i++){
            cin >> s[i][1] >> s[i][2];
            l1[i] = s[i][1].length();
//            s[i][1] = ' '+s[i][1];
//            s[i][2] = ' '+s[i][2];
            if(i>=2){
                pref[i] = pref[i-1]+l1[i-1];
            }
            else{
                pref[i] = 1;
            }
            for(int j=1;j<=l1[i];j++){
                if(j==1){
                    hsh1[pref[i]][1] = s[i][1][1]*pwr1[1];
                    hsh2[pref[i]][1] = s[i][1][1]*pwr2[1];
                    hsh1[pref[i]][2] = s[i][2][1]*pwr1[1];
                    hsh2[pref[i]][2] = s[i][2][1]*pwr2[1];
                    continue;
                }
                hsh1[pref[i]+j-1][1] = hsh1[pref[i]+j-2][1]+s[i][1][j]*pwr1[j];
                hsh2[pref[i]+j-1][1] = hsh2[pref[i]+j-2][1]+s[i][1][j]*pwr2[j];
                hsh1[pref[i]+j-1][2] = hsh1[pref[i]+j-2][2]+s[i][2][j]*pwr1[j];
                hsh2[pref[i]+j-1][2] = hsh2[pref[i]+j-2][2]+s[i][2][j]*pwr2[j];
            }
        }
        
        for(int i=1;i<=q;i++){
            string t1,t2;
            cin >> t1 >> t2;
            int tlen=t1.length();
            t1 = ' '+t1;
            t2 = ' '+t2;
            for(int j=1;j<=tlen;j++){
                hsh1[j][3] = hsh1[j-1][3]+t1[j]*pwr1[j];
                hsh2[j][3] = hsh2[j-1][3]+t1[j]*pwr2[j];
                hsh1[j][4] = hsh1[j-1][4]+t2[j]*pwr1[j];
                hsh2[j][4] = hsh2[j-1][4]+t2[j]*pwr2[j];
            }
            ull ans=0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=tlen-l1[j]+1;k++){
//                    if(getHash(3,k,k+l1[j]-1)==getHash(1,pref[j],pref[j]+l1[j]-1)
//                        &&getHash(3,1,tlen).first-getHash(1,pref[j],pref[j]+l1[j]-1).first*pwr1[k]+getHash(2,pref[j],pref[j]+l1[j]-1).first*pwr1[k]==getHash(4,1,tlen).first
//                        &&getHash(3,1,tlen).second-getHash(1,pref[j],pref[j]+l1[j]-1).second*pwr2[k]+getHash(2,pref[j],pref[j]+l1[j]-1).second*pwr2[k]==getHash(4,1,tlen).second){
//                        ans++;
//                    }
//                    cerr << t1.substr(0,k)+s[j][2].substr(1)+t1.substr(k+l1[j]) << t2 << " " << (t1.substr(k,l1[j])==s[j][1].substr(1)) << " " << (t1.substr(0,k)+s[j][2].substr(1)+t1.substr(k+l1[j])==t2) << "\n";
                    if(t1.substr(k,l1[j])==s[j][1]&&t1.substr(0,k)+s[j][2]+t1.substr(k+l1[j])==t2){
                        ans++;
                    }
                }
            }
            cout << ans << "\n";
        }

        return 0;
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    return Gavin::main();
}

