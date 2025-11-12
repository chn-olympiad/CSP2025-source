#include <bits/stdc++.h>
using namespace std;
int n,q;//2*10**5
string s1,s2;
int str[5000005][2];
int lon[200005][2];
int sub[200005];
int wid[200005][2];
int sub_;
int res;
bool f;
int min_,max_;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    memset(str,0,sizeof(str));
    memset(lon,0,sizeof(lon));
    memset(sub,0,sizeof(sub));
    memset(wid,0,sizeof(wid));
    for (int i=0;i<n;i++){
        min_ = 20000000;
        max_ = -100;
        cin >> s1 >> s2;
        if (i == 0){
            lon[0][0] = 0;
            lon[0][1] = s1.length()-1;
        }
        else{
            lon[i][0] = lon[i-1][1]+1;
            lon[i][1] = lon[i][0]+s1.length()-1;
        }
        for (int j=0;j<s1.length();j++){
            str[lon[i][0]+j][0] = s1[j]-'a';
            str[lon[i][0]+j][1] = s2[j]-'a';
            if (s1[j]!=s2[j]){
                sub[i]++;
                min_ = min(min_,j);
                max_ = max(max_,j);
            }
        }
        if (sub[i]){
            wid[i][0] = min_;
            wid[i][1] = max_;
        }
    }
    for(int i=0;i<q;i++){
        cin >> s1 >> s2;
        min_ = 20000000;
        max_ = -100;
        sub_ = 0;
        res = 0;
        for (int j=0;j<s1.length();j++){
            if (s1[j]!=s2[j]){
                sub_++;
                min_ = min(min_,j);
                max_ = max(max_,j);
            }
        }
        for (int j=0;j<n;j++){
            f = 1;
            if (sub[j] == sub_){
                if (max_-min_ == wid[j][1]-wid[j][0]){
                    if (min_>=wid[j][0]&&s1.length()-max_>=lon[j][1]-lon[j][0]+1-wid[j][1]){
                        for (int k=0;k<lon[j][1]-lon[j][0]+1;k++){
                            if (s1[min_-wid[j][0]+k]!=str[lon[j][0]+k][0]+'a'){
                                f = 0;
                                break;
                            }
                            if (s2[min_-wid[j][0]+k]!=str[lon[j][0]+k][1]+'a'){
                                f = 0;
                                break;
                            }
                        }
                    }
                    else f=0;
                }
                else f=0;
            }
            else f=0;
            if (f){
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}