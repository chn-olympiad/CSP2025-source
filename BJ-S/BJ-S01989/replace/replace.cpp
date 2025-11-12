#include<bits/stdc++.h>
using namespace std;
string s1,s2;
map<string,string>mp;
int n,q,cnt,s,e;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1; i<= n; i++){
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    while(q--){
        cnt = 0;
        cin >> s1 >> s2;
        int l = s1.length();
        int l1 = s2.length();
        if(l != l1){
            printf("0\n");
            continue;
        }
        for(int i = 0; i< l; i++){
            if(s1[i] != s2[i]){
                s = i;
                break;
            }
        }
        for(int i = l - 1; i >= 0; i--){
            if(s1[i] != s2[i]){
                e = i;
                break;
            }
        }
        for(int i = 0; i<= s; i++){
            for(int j = l - 1; j >= e; j--){
                string S1 = "",S2 = "";
                for(int k = i; k<= j; k++){
                    S1 = S1 + s1[k];
                    S2 = S2 + s2[k];
                }
                if(mp[S1] == S2) cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
