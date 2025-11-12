#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,S;
    cin >> s;
    int cnt = s.size();
    for(int i=0;i<cnt;i++){
        if(s[i]>='0'&&s[i]<='9'){
            S+=s[i];
        }
    }
    char t;
    int CNT = S.size();
    for(int i=0;i<CNT-1;i++){
        for(int j=i+1;j<CNT;j++){
            if(S[i]<S[j]){
                t=S[i];
                S[i]=S[j];
                S[j]=t;
            }
        }
    }
    for(int i=0;i<CNT;i++){
        cout << S[i];
    }
    return 0;
}
