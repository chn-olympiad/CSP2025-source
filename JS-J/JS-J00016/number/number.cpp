#include <bits/stdc++.h>
using namespace std;
int a[1000010];

bool cmp(int x,int y){
    return x > y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cnt = s.size();
    for(int i = 0;i < cnt;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[i] = s[i];
        }
    }sort(a,a + cnt,cmp);
    for(int i = 0;i <= cnt;i++){
        cout << (char)a[i];
    }fclose(stdin);
    fclose(stdout);
    return 0;
}
