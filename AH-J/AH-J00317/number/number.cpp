#include<bits/stdc++.h>
using namespace std;

char s[1000001];
char t[1000001];
char t2[1000001];
char maxt;
char x[1000001];
int xi;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i = 0;i < 1000001;i++){
        cin >> s[i];
    }
    for(int i = 0;i < 1000001;i++){
        if(s[i] <= '9' && s[i] >= '0'){
            t[i] = s[i];
            for(int j = 0;j < 1000001;j++){
                if(t[i] > maxt){
                    maxt = t[i];
                }
            }
            x[xi] = maxt;
            xi++;
            t[i] = 0;
            maxt = 0;
        } else t2[i] = s[i];

    }
    sort(x+0,x+xi,cmp);
    for(int i = 0;i < xi;i++){
        cout << x[i];
    }
    return 0;
}
